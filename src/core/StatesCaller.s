.include "global.s"
.include "macro.i"

.area _CODE

.globl _state_start_fns, _state_update_fns

.globl _scene_type
.globl __current_bank

_state_init::
        ld hl, #_state_start_fns
        jr state_call

_state_update::
        ld hl, #_state_update_fns

state_call:
        ld a, (#_scene_type)
        ld e, a
        add a
        add e
        add l
        ld l, a
        adc h
        sub l
        ld h, a
        ldh a, (#__current_bank)
        push af
        ld a, (hl+)
        ldh (#__current_bank), a
        ld (0x2000), a
        ld a, (hl+)
        ld h, (hl)
        ld l, a
        rst 0x20
        pop af
        ldh (#__current_bank), a
        ld (0x2000), a
        ret
        