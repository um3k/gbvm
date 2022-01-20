.module script_input_0

.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

ACTOR = -4

___bank_script_input_0 = 255
.globl ___bank_script_input_0
.CURRENT_SCRIPT_BANK == ___bank_script_input_0

_script_input_0::
        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Push Scene State
        VM_SCENE_PUSH

        ; Load Scene
        ; Stop Script
        VM_STOP
