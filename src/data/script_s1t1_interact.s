.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255



___bank_script_s1t1_interact = 255
.globl ___bank_script_s1t1_interact

_script_s1t1_interact::

        ; If Variable True
        VM_IF_CONST .EQ         VAR_QUEST2, 1, 1$, 0
        VM_JUMP                 2$
1$:
        ; Load Scene
        ; NOT IMPLEMENTED
2$:
        ; Stop Script
        VM_STOP
