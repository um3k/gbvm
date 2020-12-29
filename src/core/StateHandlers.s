.area _CODE

.globl  b_topdown_init, _topdown_init, b_topdown_update, _topdown_update
.globl  b_platform_init, _platform_init, b_platform_update, _platform_update
.globl  b_adventure_init, _adventure_init, b_adventure_update, _adventure_update
.globl  b_shmup_init, _shmup_init, b_shmup_update, _shmup_update
.globl  b_pointnclick_init, _pointnclick_init, b_pointnclick_update, _pointnclick_update

_state_start_fns::
    .dw _topdown_init, _platform_init, _adventure_init, _shmup_init, _pointnclick_init 

_state_update_fns::
    .dw _topdown_update, _platform_update, _adventure_update, _shmup_update, _pointnclick_update

_stateBanks::
    .db b_topdown_init, b_platform_init, b_adventure_init, b_shmup_init, b_pointnclick_init