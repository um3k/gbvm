.include "vm.i"
.include "data/game_globals.i"
.include "macro.i"

.globl b_wait_frames, _wait_frames, ___bank_scene_8, _scene_8

.area _CODE_255

ACTOR = -4

___bank_script_s10t4_interact = 255
.globl ___bank_script_s10t4_interact

_script_s10t4_interact::
        VM_LOCK

        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; If Input
        VM_PUSH_CONST           0
        VM_GET_INT8             .ARG0, ^/(_joypads + 1)/
        VM_RPN
            .R_REF      .ARG0
            .R_INT8     4
            .R_OPERATOR .B_AND
            .R_STOP
        VM_IF_CONST .NE         .ARG0, 0, 1$, 2
        VM_JUMP                 2$
1$:
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 0
        VM_ACTOR_ACTIVATE       ACTOR

        ; Actor Set Direction
        VM_ACTOR_SET_DIR        ACTOR, .DIR_UP

        ; Wait N Frames
        VM_PUSH_CONST           6
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Load Scene
        VM_FADE_OUT             2
        VM_SET_CONST            ACTOR, 0
        VM_SET_CONST            ^/(ACTOR + 1)/, 1152
        VM_SET_CONST            ^/(ACTOR + 2)/, 768
        VM_ACTOR_SET_POS        ACTOR
        VM_ACTOR_SET_DIR        ACTOR, .DIR_UP
        VM_RAISE                EXCEPTION_CHANGE_SCENE, 3
            IMPORT_FAR_PTR_DATA _scene_8

2$:

        ; Stop Script
        VM_STOP
