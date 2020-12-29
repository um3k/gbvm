.area _CODE

.globl _scene_type
.globl __current_bank

.globl  b_topdown_init, _topdown_init, b_topdown_update, _topdown_update
.globl  b_platform_init, _platform_init, b_platform_update, _platform_update
.globl  b_adventure_init, _adventure_init, b_adventure_update, _adventure_update
.globl  b_shmup_init, _shmup_init, b_shmup_update, _shmup_update
.globl  b_pointnclick_init, _pointnclick_init, b_pointnclick_update, _pointnclick_update

_state_start_fns:
    .db b_topdown_init
    .dw _topdown_init 

    .db b_platform_init
    .dw _platform_init
    
    .db b_adventure_init  
    .dw _adventure_init 
    
    .db b_shmup_init
    .dw _shmup_init 
    
    .db b_pointnclick_init
    .dw _pointnclick_init

_state_update_fns:
    .db b_topdown_update
    .dw _topdown_update 

    .db b_platform_update
    .dw _platform_update
    
    .db b_adventure_update  
    .dw _adventure_update 
    
    .db b_shmup_update
    .dw _shmup_update 
    
    .db b_pointnclick_update
    .dw _pointnclick_update


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
        