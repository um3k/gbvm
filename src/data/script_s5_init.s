.include "vm.i"
.include "data/game_globals.i"

.globl ___bank_spritesheet_1, _spritesheet_1
.globl b_wait_frames, _wait_frames

.area _CODE_255

___bank_script_s5_init = 255
.globl ___bank_script_s5_init
.globl ___bank_script_s5_timer1, _script_s5_timer1 

ACTOR = -4

_script_s5_init::
        VM_LOCK

        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           256
        VM_PUSH_CONST           256
        VM_PUSH_CONST           ^/(.ACTOR_ATTR_H_FIRST | .ACTOR_ATTR_CHECK_COLL)/

        ; ; Actor 1 Face Left
        VM_SET_CONST            ACTOR, 1
        VM_ACTOR_SET_DIR        ACTOR, .DIR_LEFT

        ; ; Actor 1 Face Left
        VM_SET_CONST            ACTOR, 2
        VM_ACTOR_SET_DIR        ACTOR, .DIR_RIGHT

        ; Wait 1 frame to allow actors to rerender before fade in starts
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade IN
        VM_FADE_IN              .UI_MODAL

        ; Emote
        ; VM_SET_CONST            ACTOR, 0
        ; VM_ACTOR_EMOTE          ACTOR, ___bank_spritesheet_1, _spritesheet_1

        ; VM_ACTOR_MOVE_TO        ACTOR
        
        ; Text Dialogue
        ; VM_LOAD_TEXT            0
        ; .asciz "Hello\nWorld.\nCheck\nwindow\noverlaying\nactors."
        ; VM_OVERLAY_MOVE_TO      0, 10, .OVERLAY_TEXT_IN_SPEED
        ; VM_DISPLAY_TEXT         0, 0, 0
        ; VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        ; VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        ; VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        VM_MUSIC_ROUTINE        0, ___bank_script_s5_timer1, _script_s5_timer1
        VM_MUSIC_ROUTINE        1, ___bank_script_s5_timer1, _script_s5_timer1
        VM_MUSIC_ROUTINE        2, ___bank_script_s5_timer1, _script_s5_timer1
        VM_MUSIC_ROUTINE        3, ___bank_script_s5_timer1, _script_s5_timer1
        VM_MUSIC_PLAY           4, 1

        ; Stop Script
        VM_STOP

___bank_TESTFN01 = 1
.globl ___bank_TESTFN01
