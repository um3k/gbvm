.module script_s0a0_update

.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

ACTOR = -4

___bank_script_s0a0_update = 255
.globl ___bank_script_s0a0_update
.CURRENT_SCRIPT_BANK == ___bank_script_s0a0_update

_script_s0a0_update::
        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

1$:
        ; If Variable True
        VM_IF_CONST .GT         VAR_S0A0_KILLED, 0, 2$, 0
        ; Variable Set To Random
        VM_RAND                 VAR_S0A0_RAND_X, 0, 19

        ; Variable Set To Random
        VM_RAND                 VAR_S0A0_RAND_Y, 1, 17

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 1

        ; Actor Move To Variables
        VM_RPN
            .R_REF      VAR_S0A0_RAND_X
            .R_INT16    128
            .R_OPERATOR .MUL
            .R_REF      VAR_S0A0_RAND_Y
            .R_INT16    128
            .R_OPERATOR .MUL
            .R_STOP
        VM_SET                  ^/(ACTOR + 1 - 2)/, .ARG1
        VM_SET                  ^/(ACTOR + 2 - 2)/, .ARG0
        VM_POP                  2
        VM_SET_CONST            ^/(ACTOR + 3)/, ^/(.ACTOR_ATTR_CHECK_COLL | .ACTOR_ATTR_H_FIRST)/
        VM_ACTOR_MOVE_TO        ACTOR

        VM_JUMP                 3$
2$:
3$:

        VM_IDLE

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        VM_JUMP                 1$
        ; Stop Script
        VM_STOP
