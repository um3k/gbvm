.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

ACTOR = -4

___bank_script_s7_init = 255
.globl ___bank_script_s7_init

_script_s7_init::
        VM_LOCK

        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Call Script: Init Weapons
        VM_CALL_FAR             ___bank_script_custom_1, _script_custom_1

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade In
        VM_FADE_IN              1

        ; Player Set Spritesheet
        VM_SET_CONST            ACTOR, 0
        VM_ACTOR_SET_SPRITESHEET ACTOR, ___bank_spritesheet_1, _spritesheet_1

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 0
        VM_ACTOR_ACTIVATE       ACTOR

        ; Actor Set Movement Speed
        VM_ACTOR_SET_MOVE_SPEED ACTOR, 8

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 0
        VM_ACTOR_ACTIVATE       ACTOR

        ; Actor Move Relative
        VM_ACTOR_GET_POS        ACTOR
        VM_RPN
            .R_REF      ^/(ACTOR + 1)/
            .R_INT16    512
            .R_OPERATOR .ADD
            .R_REF      ^/(ACTOR + 2)/
            .R_INT16    0
            .R_OPERATOR .ADD
            .R_STOP
        VM_SET                  ^/(ACTOR + 1 - 2)/, .ARG1
        VM_SET                  ^/(ACTOR + 2 - 2)/, .ARG0
        VM_POP                  2
        VM_SET_CONST            ^/(ACTOR + 3)/, ^/(.ACTOR_ATTR_H_FIRST)/
        VM_ACTOR_MOVE_TO        ACTOR

        ; Music Play
        VM_MUSIC_PLAY           ___bank_music_track_0__Data, _music_track_0__Data, .MUSIC_LOOP

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 0
        VM_ACTOR_ACTIVATE       ACTOR

        ; Actor Set Movement Speed
        VM_ACTOR_SET_MOVE_SPEED ACTOR, 16

        ; Stop Script
        VM_STOP
