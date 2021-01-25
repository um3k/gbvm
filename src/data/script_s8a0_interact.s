.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255



___bank_script_s8a0_interact = 255
.globl ___bank_script_s8a0_interact

_script_s8a0_interact::
        VM_LOCK

        ; Text Dialogue
        VM_LOAD_TEXT            0
        .asciz "Locked...\n"
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT         0, 0, 0
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/
        ; Stop Script
        VM_STOP
