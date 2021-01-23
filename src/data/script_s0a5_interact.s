.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255



___bank_script_s0a5_interact = 255
.globl ___bank_script_s0a5_interact

_script_s0a5_interact::

        VM_LOCK

        ; Text Dialogue
        VM_LOAD_TEXT            0
        .asciz "Game was saved!\nIt is now safe to\nturn off game boy."
        VM_OVERLAY_MOVE_TO      0, 13, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT         0, 0, 0
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        VM_RAISE                EXCEPTION_SAVE, 0

        ; Stop Script
        VM_STOP
