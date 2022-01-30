.module script_input_0

.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

.LOCAL_ACTOR = -4

___bank_script_input_0 = 255
.globl ___bank_script_input_0

_script_input_0::
        VM_RESERVE              4

        ; Push Scene State
        VM_SCENE_PUSH

        ; Load Scene
        ; Stop Script
        VM_STOP
