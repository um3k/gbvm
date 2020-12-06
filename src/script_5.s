.include "vm.inc"
        
.globl b_actor_move_to, _actor_move_to

.area _CODE_3

___bank_SCRIPT_5 = 3
.globl ___bank_SCRIPT_5

_SCRIPT_5::

        VM_PUSH         3       ; Actor 7
        VM_PUSH         0       ; X = 80
        VM_PUSH         80      ; Y = 80
        VM_PUSH         0       ; Horizonal movement first
        VM_PUSH         0       ; Don't check collisions
1$:
        ; Actor Move To
        VM_SET_CONST    .ARG3, 144
        VM_INVOKE       b_actor_move_to, _actor_move_to, 0, .ARG4       ; call actor_move_to()

        ; Actor Move To
        VM_SET_CONST    .ARG3, 0
        VM_INVOKE       b_actor_move_to, _actor_move_to, 0, .ARG4       ; call actor_move_to()

        VM_JUMP 1$
