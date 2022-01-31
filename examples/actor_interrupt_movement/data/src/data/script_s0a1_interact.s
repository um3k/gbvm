.module script_s0a1_interact

.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

ACTOR = -4

___bank_script_s0a1_interact = 255
.globl ___bank_script_s0a1_interact
.CURRENT_SCRIPT_BANK == ___bank_script_s0a1_interact

_script_s0a1_interact::
        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; If Parameter 0 Equals 8
        VM_PUSH_CONST           0
        VM_GET_TLOCAL           .ARG0, 0
        VM_IF_CONST .EQ         .ARG0, 8, 1$, 1
        VM_JUMP                 2$
1$:
        ; If Variable True
        VM_IF_CONST .GT         VAR_S0A0_KILLED_1, 0, 3$, 0
        ; Variable Set To True
        VM_SET_CONST            VAR_S0A0_KILLED_1, 1

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 2

        VM_ACTOR_INTERRUPT_MOVEMENT ACTOR

        VM_JUMP                 4$
3$:
        ; Variable Set To False
        VM_SET_CONST            VAR_S0A0_KILLED_1, 0

4$:

        ; Stop Script
        VM_STOP
2$:

        ; Stop Script
        VM_STOP
