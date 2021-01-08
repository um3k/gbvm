#pragma bank 1

#include <string.h>

#include "LoadSave.h"

#include "actor.h"
#include "vm.h"
#include "events.h"

#define SAVE(A) memcpy(save_data, &(A), sizeof(A)), save_data+=sizeof(A) 
#define LOAD(A) memcpy(&(A), save_data, sizeof(A)), save_data+=sizeof(A) 

const UINT32 signature = 0x45564153;

UBYTE data_is_saved() __banked {
    SWITCH_RAM_MBC5(0);
    UBYTE * save_data = (UBYTE *)0xA000;
    return (*((UINT32 *)save_data) == signature);
}

void data_save() __banked {
    SWITCH_RAM_MBC5(0);
    UBYTE * save_data = (UBYTE *)0xA000;
    *((UINT32 *)save_data) = signature; save_data += sizeof(signature);

    // actors
    SAVE(actors);
    SAVE(actors_active_head); SAVE(actors_inactive_head); SAVE(player_moving); SAVE(player_collision_actor);
    // VM contexts
    SAVE(CTXS);
    SAVE(first_ctx); SAVE(free_ctxs); SAVE(vm_lock_state);
}

UBYTE data_load() __banked {
    if (!data_is_saved()) return FALSE;
    SWITCH_RAM_MBC5(0);
    UBYTE * save_data = (UBYTE *)0xA000 + sizeof(signature);

    // actors
    LOAD(actors); 
    LOAD(actors_active_head); LOAD(actors_inactive_head); LOAD(player_moving); LOAD(player_collision_actor);
    // VM contexts
    LOAD(CTXS);
    LOAD(first_ctx); LOAD(free_ctxs); LOAD(vm_lock_state);

    return TRUE;
}