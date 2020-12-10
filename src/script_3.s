.include "vm.i"
        
.globl b_wait_frames, _wait_frames

.area _CODE_4

___bank_SCRIPT_3 = 4
.globl ___bank_SCRIPT_3

_SCRIPT_3::
; five initial arguments are pushed by script caller
;        VM_RESERVE      5
1$:
        ; Wait 1 Second
        VM_PUSH         60
        VM_INVOKE       b_wait_frames, _wait_frames, 1, .ARG0           ; wait 1 second, dispose argument on stack

        ; Actor Move To
        VM_RPN
            .R_REF      .ARG3
            .R_INT16    32
            .R_OPERATOR .SUB
            .R_REF      .ARG2
            .R_INT16    48
            .R_OPERATOR .SUB
            .R_STOP                                                     ; two results are left on stack!
        VM_SET          .ARG5, .ARG1
        VM_SET          .ARG4, .ARG0
        VM_POP          2                                               ; dispose results of RPN eval
        VM_ACTOR_MOVE_TO .ARG4

        ; Wait 1 Second
        VM_PUSH         60
        VM_INVOKE       b_wait_frames, _wait_frames, 1, .ARG0           ; wait 1 second, dispose argument on stack

        ; Actor Move To
        VM_RPN
            .R_REF      .ARG3
            .R_INT16    32
            .R_OPERATOR .ADD
            .R_REF      .ARG2
            .R_INT16    48
            .R_OPERATOR .ADD
            .R_STOP                                                     ; two results are left on stack!
        VM_SET          .ARG5, .ARG1
        VM_SET          .ARG4, .ARG0
        VM_POP          2                                               ; dispose results of RPN eval
        VM_ACTOR_MOVE_TO .ARG4
        VM_JUMP 1$
