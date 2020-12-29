.area _CODE

.globl _scene_type
.globl __current_bank

.globl  b_topdown_init, _topdown_init, b_topdown_update, _topdown_update
.globl  b_platform_init, _platform_init, b_platform_update, _platform_update
.globl  b_adventure_init, _adventure_init, b_adventure_update, _adventure_update
.globl  b_shmup_init, _shmup_init, b_shmup_update, _shmup_update
.globl  b_pointnclick_init, _pointnclick_init, b_pointnclick_update, _pointnclick_update

.macro FAR_PTR SYM
    .db b'SYM
    .dw SYM
.endm

_state_start_fns:
    FAR_PTR _topdown_init
    FAR_PTR _platform_init
    FAR_PTR _adventure_init 
    FAR_PTR _shmup_init 
    FAR_PTR _pointnclick_init

_state_update_fns:
    FAR_PTR _topdown_update 
    FAR_PTR _platform_update
    FAR_PTR _adventure_update 
    FAR_PTR _shmup_update 
    FAR_PTR _pointnclick_update

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
        