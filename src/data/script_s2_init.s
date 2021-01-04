.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

___bank_script_s2_init = 255
.globl ___bank_script_s2_init
.globl ___bank_script_s2_timer1, _script_s2_timer1 

_script_s2_init::
        VM_LOCK

        ; Actor 1 Face Right
        VM_PUSH                 1
        VM_ACTOR_SET_DIR        .ARG0, .DIR_RIGHT, 0
        VM_POP                  1

        ; Fade IN
        VM_FADE_IN              .UI_MODAL

        ; Text Dialogue
        VM_LOAD_TEXT            0
        .asciz "Hello\nWorld.\nCheck\nwindow\noverlaying\nactors."
        VM_OVERLAY_MOVE_TO      0, 10, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT         0, 0, 0
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/


        VM_MUSIC_PLAY           2, 1

        VM_TIMER_PREPARE        1, ___bank_script_s2_timer1, _script_s2_timer1
        VM_TIMER_SET            1, 5

        ; Stop Script
        VM_STOP
