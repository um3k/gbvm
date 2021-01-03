.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

___bank_script_s2_init = 255
.globl ___bank_script_s2_init

_script_s2_init::
        VM_LOCK

        ; Text Dialogue
        VM_LOAD_TEXT            0
        .asciz "Hello\nWorld.\nCheck\nwindow\noverlaying\nactors."
        VM_OVERLAY_MOVE_TO      0, 10, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT         0, 0, 0
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        ; Actor 1 Face Right
        VM_PUSH                 1
        VM_ACTOR_SET_DIR        .ARG0, .DIR_RIGHT, 0
        VM_POP                  1

        VM_MUSIC_PLAY           2, 1

        ; Stop Script
        VM_STOP
