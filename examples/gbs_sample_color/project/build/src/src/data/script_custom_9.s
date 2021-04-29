.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

ACTOR = -4

___bank_script_custom_9 = 255
.globl ___bank_script_custom_9

_script_custom_9::
        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 0
        VM_ACTOR_ACTIVATE       ACTOR

        VM_POP                  4
        VM_RET_FAR
