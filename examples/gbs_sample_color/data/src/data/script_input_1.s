.module script_input_1

.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

ACTOR = -4

___bank_script_input_1 = 255
.globl ___bank_script_input_1
.CURRENT_SCRIPT_BANK == ___bank_script_input_1

_script_input_1::
        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 0

        ; Stop Script
        VM_STOP
