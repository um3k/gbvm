.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

ACTOR = -4

___bank_script_s6_init = 255
.globl ___bank_script_s6_init

_script_s6_init::
        VM_LOCK

        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade In
        VM_FADE_IN              1

        ; Call Script: Initialize Menu
        VM_CALL_FAR             ___bank_script_custom_0, _script_custom_0

        ; If Variable True
        VM_IF_CONST .GT         VAR_PUSHEDICEBLOCK, 0, 1$, 0
        VM_JUMP                 2$
1$:
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 2
        VM_ACTOR_ACTIVATE       ACTOR

        ; Actor Set Position
        VM_SET_CONST            ^/(ACTOR + 1)/, 3072
        VM_SET_CONST            ^/(ACTOR + 2)/, 1920
        VM_ACTOR_SET_POS        ACTOR

2$:

        ; Stop Script
        VM_STOP
