.include "vm.inc"
        
.area _CODE_4

___bank_SCRIPT_5 = 4
.globl ___bank_SCRIPT_5

_SCRIPT_5::

        VM_PUSH                 3       ; Actor 3
        VM_PUSH                 0       ; X = 80
        VM_PUSH                 32      ; Y = 80
        VM_PUSH                 0       ; Horizonal movement first
        VM_PUSH                 0       ; Don't check collisions
1$:
        ; Actor Move To
        VM_SET_CONST            .ARG3, 144
        VM_ACTOR_MOVE_TO        .ARG4       ; call actor_move_to()

        ; Actor Move To
        VM_SET_CONST            .ARG3, 0
        VM_ACTOR_MOVE_TO        .ARG4       ; call actor_move_to()

        VM_SET_CONST            .ARG2, 144
        VM_ACTOR_MOVE_TO        .ARG4       ; call actor_move_to()

        VM_SET_CONST            .ARG2, 32
        VM_ACTOR_MOVE_TO        .ARG4       ; call actor_move_to()

        VM_JUMP 1$
