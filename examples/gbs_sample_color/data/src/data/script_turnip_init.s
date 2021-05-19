.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

ACTOR = -4

___bank_script_turnip_init = 255
.globl ___bank_script_turnip_init

_script_turnip_init::
        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; If Variable True
        VM_PUSH_VALUE_IND       ^/(.ARG2 - 4)/
        VM_IF_CONST .GT         .ARG0, 0, 1$, 1
        VM_JUMP                 2$
1$:
        ; Actor Hide
        VM_SET                  ACTOR, ^/(.ARG3 - 4)/
        VM_ACTOR_SET_HIDDEN     ACTOR, 1
        VM_ACTOR_DEACTIVATE     ACTOR

        ; Actor Set Active
        VM_SET                  ACTOR, ^/(.ARG3 - 4)/

        ; Actor Set Position
        VM_SET_CONST            ^/(ACTOR + 1)/, 0
        VM_SET_CONST            ^/(ACTOR + 2)/, 0
        VM_ACTOR_SET_POS        ACTOR

2$:

        VM_POP                  4
        VM_RET_FAR
