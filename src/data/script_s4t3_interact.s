.include "vm.i"
.include "data/game_globals.i"
.include "macro.i"

.area _CODE_255

___bank_script_s4t3_interact = 255
.globl ___bank_script_s4t3_interact

_script_s4t3_interact::
        VM_SET_CONST_INT16      _pl_vel_y, -16384
        VM_SET_CONST_INT16      _pl_vel_x, 28912
        VM_STOP
