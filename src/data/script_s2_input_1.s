.include "vm.i"
.include "data/game_globals.i"

___bank_script_s2_input1    = 255
.globl ___bank_script_s2_input1

_script_s2_input1::
        VM_OVERLAY_SHOW         0, 18, .UI_COLOR_BLACK
        VM_OVERLAY_MOVE_TO      0, 9, .OVERLAY_TEXT_IN_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_BTN_ANY)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW)/
        VM_STOP
