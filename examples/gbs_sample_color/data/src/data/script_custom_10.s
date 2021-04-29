.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

ACTOR = -4

___bank_script_custom_10 = 255
.globl ___bank_script_custom_10

_script_custom_10::
        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 0
        VM_ACTOR_ACTIVATE       ACTOR

        ; Wait N Frames
        VM_PUSH_CONST           60
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        VM_POP                  4
        VM_RET_FAR
