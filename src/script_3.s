.include "vm.inc"
        
.globl b_actor_move_to, _actor_move_to
.globl b_wait_frames, _wait_frames

.area _CODE_3

___bank_SCRIPT_3 = 3
.globl ___bank_SCRIPT_3

_SCRIPT_3::
        VM_PUSH         5       ; Actor 5
        VM_PUSH         0       ; X = 0
        VM_PUSH         0       ; Y = 0
        VM_PUSH         0       ; Horizonal movement first
        VM_PUSH         0       ; Don't check collisions
1$:
        ; Wait 1 Second
        VM_PUSH         60
        VM_INVOKE       b_wait_frames, _wait_frames, 1, .ARG0           ; wait 1 second, dispose argument on stack

        ; Actor Move To
        VM_SET_CONST    .ARG3, 0
        VM_SET_CONST    .ARG2, 16
        VM_INVOKE       b_actor_move_to, _actor_move_to, 0, .ARG4       ; call actor_move_to()

        ; Wait 1 Second
        VM_PUSH         60
        VM_INVOKE       b_wait_frames, _wait_frames, 1, .ARG0           ; wait 1 second, dispose argument on stack

        ; Actor Move To
        VM_SET_CONST    .ARG3, 32
        VM_SET_CONST    .ARG2, 64
        VM_INVOKE       b_actor_move_to, _actor_move_to, 0, .ARG4       ; call actor_move_to()
        VM_JUMP 1$
