.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

___bank_script_s5_timer1 = 255
.globl ___bank_script_s5_timer1

_script_s5_timer1::
        VM_PUSH                 1
        VM_IF_CONST     .EQ     VAR_ACTOR_DIRECTION, 0, 1$, 0
        VM_ACTOR_SET_DIR        .ARG0, .DIR_LEFT, 0
        VM_SET_CONST            .ARG0, 2
        VM_ACTOR_SET_DIR        .ARG0, .DIR_RIGHT, 0
        VM_SET_CONST            VAR_ACTOR_DIRECTION, 0
        VM_POP                  1
        VM_STOP
1$:
        VM_ACTOR_SET_DIR        .ARG0, .DIR_RIGHT, 0
        VM_SET_CONST            .ARG0, 2
        VM_ACTOR_SET_DIR        .ARG0, .DIR_LEFT, 0
        VM_SET_CONST            VAR_ACTOR_DIRECTION, 1
        VM_POP                  1
        VM_STOP
