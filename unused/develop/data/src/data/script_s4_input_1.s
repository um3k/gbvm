.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

___bank_script_s4_input1    = 255
.globl ___bank_script_s4_input1
.globl _pl_vel_x, _pl_vel_y

_script_s4_input1::

        VM_STOP
