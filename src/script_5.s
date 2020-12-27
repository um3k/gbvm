.include "vm.i"
        
.area _CODE_255

___bank_SCRIPT_5 = 255
.globl ___bank_SCRIPT_5

_SCRIPT_5::

        VM_PUSH                 3       ; Actor 3
        VM_PUSH                 0       ; X = 80
        VM_PUSH                 32      ; Y = 80
        VM_PUSH                 ^/(.ACTOR_ATTR_H_FIRST | .ACTOR_ATTR_CHECK_COLL)/ ; attributes

        VM_ACTOR_ACTIVATE       .ARG3
1$:
        VM_SET_CONST            .ARG2, 144
        VM_ACTOR_MOVE_TO        .ARG3       ; call actor_move_to()

        VM_SET_CONST            .ARG1, 144
        VM_ACTOR_MOVE_TO        .ARG3       ; call actor_move_to()

        VM_SET_CONST            .ARG2, 0
        VM_ACTOR_MOVE_TO        .ARG3       ; call actor_move_to()

        VM_SET_CONST            .ARG1, 32
        VM_ACTOR_MOVE_TO        .ARG3       ; call actor_move_to()

        VM_JUMP 1$
