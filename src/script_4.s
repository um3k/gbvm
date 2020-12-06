.include "vm.inc"
        
.globl b_actor_move_to, _actor_move_to
.globl b_wait_frames, _wait_frames

.area _CODE_3

___bank_SCRIPT_4 = 3
.globl ___bank_SCRIPT_4

_SCRIPT_4::

1$:
        ; Wait 1 Second
        VM_SET_CONST    .ARG0, 60       ; Actor 1
        VM_INVOKE       b_wait_frames _wait_frames 1  ; call actor_move_to(), dispose 5 parameter on stack after

        ; Actor Move To
        VM_SET_CONST    .ARG4, 7       ; Actor 7
        VM_SET_CONST    .ARG3, 80      ; X = 80
        VM_SET_CONST    .ARG2, 16      ; Y = 16
        VM_SET_CONST    .ARG1, 0       ; Horizonal movement first
        VM_SET_CONST    .ARG0, 0       ; Don't check collisions
        VM_INVOKE       b_actor_move_to _actor_move_to 5  ; call actor_move_to(), dispose 5 parameter on stack after

        ; Wait 1 Second
        VM_SET_CONST    .ARG0, 60       ; Actor 1
        VM_INVOKE       b_wait_frames _wait_frames 1  ; call actor_move_to(), dispose 5 parameter on stack after

        ; Actor Move To
        VM_SET_CONST    .ARG4, 7       ; Actor 7
        VM_SET_CONST    .ARG3, 48      ; X = 48
        VM_SET_CONST    .ARG2, 64      ; Y = 64
        VM_SET_CONST    .ARG1, 0       ; Horizonal movement first
        VM_SET_CONST    .ARG0, 0       ; Don't check collisions
        VM_INVOKE       b_actor_move_to _actor_move_to 5  ; call actor_move_to(), dispose 5 parameter on stack after

        VM_IDLE
        VM_JUMP 1$
