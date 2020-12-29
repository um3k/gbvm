.area _CODE

.globl  b_topdown_init, _topdown_init, b_topdown_update, _topdown_update

_state_start_fns::
    .dw _topdown_init

_state_update_fns::
    .dw _topdown_update

_stateBanks::
    .db b_topdown_init