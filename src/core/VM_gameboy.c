#include "VM_gameboy.h"

#include "vm.h"

#include "Sprite.h"
#include "Input.h"
#include "events.h"
#include "FadeManager.h"

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

void vm_context_prepate(SCRIPT_CTX * THIS, UBYTE slot, UBYTE bank, UBYTE * pc) __banked {
    THIS;
    if (!slot) return;
    script_event_t * event = &input_events[slot - 1];
    event->script_bank = bank; 
    event->script_addr = pc;
}

void vm_input_attach(SCRIPT_CTX * THIS, UBYTE mask, UBYTE slot) __banked {
    THIS;
    UBYTE * current_slot = event_slots;
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