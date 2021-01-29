.include "vm.i"
.include "data/game_globals.i"
.include "macro.i"

.area _CODE_255

___bank_script_s4t3_interact = 255
.globl ___bank_script_s4t3_interact
.globl _pl_vel_x, _pl_vel_y

_script_s4t3_interact::
        VM_PUSH                 28              ; bit less than 45 degrees 
        VM_PUSH                 100
        VM_SIN_SCALE            .ARG0, .ARG1, 6 
        VM_PUSH                 100 
        VM_COS_SCALE            .ARG0, .ARG2, 6
        VM_RPN
            .R_INT16    -360
            .R_REF      .ARG1
            .R_OPERATOR '*'
            .R_INT16    220
            .R_REF      .ARG0
            .R_OPERATOR '*'
            .R_STOP
        VM_SET_INT16            _pl_vel_y, .ARG1
        VM_SET_INT16            _pl_vel_x, .ARG0

        VM_POP                  5

        VM_STOP
