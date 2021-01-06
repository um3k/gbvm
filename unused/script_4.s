.include "vm.i"
        
.globl b_wait_frames, _wait_frames

.area _CODE_255

___bank_SCRIPT_4 = 255
.globl ___bank_SCRIPT_4

_SCRIPT_4::
        VM_PUSH         7       ; Actor 7
        VM_PUSH         0       ; X = 80
        VM_PUSH         0       ; Y = 16
        VM_PUSH         0       ; attributes
1$:
        ; Wait 1 Second
        VM_PUSH         60       ; Actor 1
        VM_INVOKE       b_wait_frames, _wait_frames, 1, .ARG0           ; wait 1 second, dispose argument on stack

        ; Actor Move To
        VM_SET_CONST    .ARG2, 80
        VM_SET_CONST    .ARG1, 16
        VM_ACTOR_MOVE_TO .ARG3

        ; Wait 1 Second
        VM_PUSH         60       ; Actor 1
        VM_INVOKE       b_wait_frames, _wait_frames, 1, .ARG0           ; wait 1 second, dispose argument on stack

        ; Actor Move To
        VM_SET_CONST    .ARG2, 48
        VM_SET_CONST    .ARG1, 64
        VM_ACTOR_MOVE_TO .ARG3       ; call actor_move_to()

        VM_JUMP 1$
