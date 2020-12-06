.include "vm.inc"
        
.globl b_actor_move_to, _actor_move_to

.area _CODE_3

___bank_SCRIPT_5 = 3
.globl ___bank_SCRIPT_5

_SCRIPT_5::

1$:
        ; Actor Move To
        VM_SET_CONST    .ARG4, 3       ; Actor 7
        VM_SET_CONST    .ARG3, 144      ; X = 80
        VM_SET_CONST    .ARG2, 80      ; Y = 80
        VM_SET_CONST    .ARG1, 0       ; Horizonal movement first
        VM_SET_CONST    .ARG0, 0       ; Don't check collisions
        VM_INVOKE       b_actor_move_to _actor_move_to 5  ; call actor_move_to(), dispose 5 parameter on stack after

        ; Actor Move To
        VM_SET_CONST    .ARG4, 3       ; Actor 7
        VM_SET_CONST    .ARG3, 0      ; X = 0
        VM_SET_CONST    .ARG2, 80      ; Y = 80
        VM_SET_CONST    .ARG1, 0       ; Horizonal movement first
        VM_SET_CONST    .ARG0, 0       ; Don't check collisions
        VM_INVOKE       b_actor_move_to _actor_move_to 5  ; call actor_move_to(), dispose 5 parameter on stack after

        VM_IDLE
        VM_JUMP 1$
