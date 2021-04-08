.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255



___bank_script_s0a0_interact = 255
.globl ___bank_script_s0a0_interact

_script_s0a0_interact::
        VM_LOCK

        ; If Variable True
        VM_IF_CONST .EQ         VAR_S0A0_IS_PLAYING, 1, 1$, 0

        VM_JUMP                 2$
1$:

2$:

        ; Stop Script
        VM_STOP
