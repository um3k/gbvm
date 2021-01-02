.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

___bank_script_s2_p_hit1 = 255
.globl ___bank_script_s2_p_hit1

_script_s2_p_hit1::

        ; Text Dialogue
        VM_LOAD_TEXT            0
        .asciz "Player hit\nCollision Group 1."
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT         0, 0, 0
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        ; Stop Script
        VM_STOP
