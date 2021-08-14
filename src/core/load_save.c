#pragma bank 4

#include <string.h>

#include "load_save.h"

#include "actor.h"
#include "vm.h"
#include "events.h"
#include "music_manager.h"
#include "data_manager.h"
#ifdef BATTERYLESS
    #include "bankdata.h"
    #include "flasher.h"
#endif

const UINT32 signature = 0x45564153;

typedef struct save_point_t {
    void * target;
    size_t size;
} save_point_t;

#define SAVEPOINT(A) {&(A), sizeof(A)}
#define SAVEPOINTS_END {0, 0}

const save_point_t save_points[] = {
    // variables (must be first, need for peeking)
    SAVEPOINT(script_memory),
    // VM contexts
    SAVEPOINT(CTXS),
    SAVEPOINT(first_ctx), SAVEPOINT(free_ctxs), SAVEPOINT(vm_lock_state),
    // intupt events
    SAVEPOINT(input_events), SAVEPOINT(input_slots), 
    // timers
    SAVEPOINT(timer_events), SAVEPOINT(timer_values),
    // music events
    SAVEPOINT(music_events),
    // scene
    SAVEPOINT(current_scene),
    // actors
    SAVEPOINT(actors),
    SAVEPOINT(actors_active_head), SAVEPOINT(actors_inactive_head), SAVEPOINT(player_moving), SAVEPOINT(player_collision_actor),
    // terminator
    SAVEPOINTS_END
};

#ifdef BATTERYLESS
    extern void _start_save; 
#endif

size_t save_blob_size;

void data_init() __banked {
    ENABLE_RAM_MBC5;
    // calculate save blob size
    save_blob_size = sizeof(signature);
    for(const save_point_t * point = save_points; (point->target); point++) {
        save_blob_size += point->size;  
    }
    // load from FLASH ROM
#ifdef BATTERYLESS
    for (UBYTE i = 0; i < BANKS_TO_SAVE; i++) restore_sram_bank(i);
#endif
}

static UBYTE * get_slot_address(UBYTE slot, UBYTE *bank) {
    UWORD res = 0, res_bank = 0;
    for (UBYTE i = 0; i < slot; i++) {
        res += save_blob_size;
        if (res > 0x2000) {
            res = 0;
            res_bank++;
            if (res_bank >= BANKS_TO_SAVE) return NULL;
        }
    }
    *bank = res_bank;
    return (UBYTE *)0xA000u + res;
}

UBYTE data_is_saved(UBYTE slot) __banked {
    UBYTE data_bank, *save_data = get_slot_address(slot, &data_bank);
    if (save_data == NULL) return FALSE;
    SWITCH_RAM_MBC5(data_bank);
    return (*((UINT32 *)save_data) == signature);
}

void data_save(UBYTE slot) __banked {
    UBYTE data_bank, *save_data = get_slot_address(slot, &data_bank);
    if (save_data == NULL) return;
    SWITCH_RAM_MBC5(data_bank);

    *((UINT32 *)save_data) = signature; save_data += sizeof(signature);    
    for(const save_point_t * point = save_points; (point->target); point++) {
        memcpy(save_data, point->target, point->size);
        save_data += point->size;  
    }
#ifdef BATTERYLESS
    save_sram(BANKS_TO_SAVE);
#endif
}

UBYTE data_load(UBYTE slot) __banked {
    if (!data_is_saved(slot)) return FALSE;

    UBYTE data_bank, *save_data = get_slot_address(slot, &data_bank) + sizeof(signature);
    SWITCH_RAM_MBC5(data_bank);

    for(const save_point_t * point = save_points; (point->target); point++) {
        memcpy(point->target, save_data, point->size);    
        save_data += point->size;  
    }   

    return TRUE;
}

void data_clear(UBYTE slot) __banked {
    UBYTE data_bank; 
    UBYTE * save_data = get_slot_address(slot, &data_bank);
    if (save_data == NULL) return;
    SWITCH_RAM_MBC5(data_bank);
    *((UINT32 *)save_data) = 0;
    
#ifdef BATTERYLESS
    save_sram(BANKS_TO_SAVE);
#endif
}

UBYTE data_peek(UBYTE slot, UINT16 idx, UBYTE count, UINT16 * dest) __banked {
    if (!data_is_saved(slot)) return FALSE;
    // if zero length block is requested then just check that save exist
    if (count) {
        UBYTE data_bank, *save_data = get_slot_address(slot, &data_bank) + sizeof(signature);
        SWITCH_RAM_MBC5(data_bank);
        memcpy(dest, save_data + idx, count << 1);
    }
    return TRUE;
}
