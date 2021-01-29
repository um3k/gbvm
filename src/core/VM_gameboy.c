#pragma bank 2

#include "VM_gameboy.h"

#include "vm.h"

#include "metasprite.h"
#include "Input.h"
#include "events.h"
#include "FadeManager.h"
#include "MusicManager.h"
#include "LoadSave.h"
#include "BankData.h"

void vm_show_sprites() __banked {
    hide_sprites = FALSE;
    SHOW_SPRITES;
}

void vm_hide_sprites() __banked {
    hide_sprites = TRUE;
    HIDE_SPRITES;
}

void vm_input_wait(SCRIPT_CTX * THIS, UBYTE mask) __banked { 
    if ((joy != last_joy) && (joy & mask)) return;
    THIS->waitable = 1;
    THIS->PC -= INSTRUCTION_SIZE + sizeof(mask);
}

void vm_context_prepare(SCRIPT_CTX * THIS, UBYTE slot, UBYTE bank, UBYTE * pc) __banked {
    THIS;
    script_event_t * event = &input_events[(slot - 1) & 7];
    event->script_bank = bank; 
    event->script_addr = pc;
}

void vm_input_attach(SCRIPT_CTX * THIS, UBYTE mask, UBYTE slot) __banked {
    THIS;
    UBYTE * current_slot = input_slots;
    for (UBYTE tmp = mask; (tmp); tmp = tmp >> 1, current_slot++) {
        if (tmp & 1) *current_slot = slot;
    }
}

void vm_input_get(SCRIPT_CTX * THIS, INT16 idx) __banked { 
    INT16 * A;
    if (idx < 0) A = THIS->stack_ptr + idx; else A = script_memory + idx;
    *A = joy;
}

void vm_fade_in(SCRIPT_CTX * THIS, UBYTE is_modal) __banked {
    THIS; 
    if (is_modal) fade_in_modal(); else fade_in();
}

void vm_fade_out(SCRIPT_CTX * THIS, UBYTE is_modal) __banked { 
    THIS;
    if (is_modal) fade_out_modal(); else fade_out();
}

void vm_timer_prepare(SCRIPT_CTX * THIS, UBYTE timer, UBYTE bank, UBYTE * pc) __banked {
    THIS;
    script_event_t * event = &timer_events[(timer - 1) & 3];
    event->script_bank = bank; 
    event->script_addr = pc;
}

void vm_timer_set(SCRIPT_CTX * THIS, UBYTE timer, UBYTE value) __banked {
    THIS;
    timer_time_t * timer_value = &timer_values[(timer - 1) & 3];
    timer_value->value = value;
    timer_value->remains = value;
}

void vm_data_is_saved(SCRIPT_CTX * THIS, INT16 idx) __banked {
    INT16 * A;
    if (idx < 0) A = THIS->stack_ptr + idx; else A = script_memory + idx;
    *A = data_is_saved();
}

void vm_replace_tile(SCRIPT_CTX * THIS, UBYTE target_tile, UBYTE tileset_bank, const tileset_t * tileset, UBYTE start_tile, UBYTE length) __banked {
    THIS;
    SetBankedBkgData(target_tile, length, tileset->tiles + (start_tile << 4), tileset_bank);
}

void vm_poll(SCRIPT_CTX * THIS, INT16 idx, INT16 res, UBYTE event_mask) __banked {
    INT16 * result_mask, * result;
    if (idx < 0) result_mask = THIS->stack_ptr + idx; else result_mask = script_memory + idx;
    if (idx < 0) result = THIS->stack_ptr + res; else result = script_memory + res;
    if (event_mask & POLL_EVENT_INPUT) { 
        if (joy != last_joy) {
            *result_mask = POLL_EVENT_INPUT;
            *result = joy;
            return;
        }
    }
    if (event_mask & POLL_EVENT_MUSIC) {
        UBYTE poll_res = music_events_poll();
        if (poll_res) { 
            *result_mask = POLL_EVENT_MUSIC;
            *result = poll_res;
            return;
        }
    }
    THIS->waitable = 1;
    THIS->PC -= INSTRUCTION_SIZE + sizeof(idx) + sizeof(res) + sizeof(event_mask);
}