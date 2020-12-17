.include "vm.i"
        
.globl b_wait_frames, _wait_frames

.area _CODE_4

___bank_SCRIPT_2        = 4
___bank_KEYS_SCRIPT     = 4

.globl ___bank_SCRIPT_2, ___bank_KEYS_SCRIPT

_UP_SCRIPT::
        VM_IF_CONST     .LTE    14, 16, 1$, 0
        VM_RPN
            .R_REF              14
            .R_INT16            16
            .R_OPERATOR         .SUB
            .R_STOP
        VM_SET                  14, .ARG0
        VM_POP                  1
        VM_ACTOR_MOVE_TO        12
        VM_STOP
1$:
        VM_SET_CONST            14, 16
        VM_ACTOR_MOVE_TO        12
        VM_STOP
_DOWN_SCRIPT::
        VM_IF_CONST     .GTE    14, ^/18 * 8/, 1$, 0
        VM_RPN
            .R_REF              14
            .R_INT16            16
            .R_OPERATOR         .ADD
            .R_STOP
        VM_SET                  14, .ARG0
        VM_POP                  1
        VM_ACTOR_MOVE_TO        12
        VM_STOP
1$:
        VM_SET_CONST            14, ^/18 * 8/
        VM_ACTOR_MOVE_TO        12
        VM_STOP
_LEFT_SCRIPT::
        VM_IF_CONST     .LTE    13, 0, 1$, 0
        VM_RPN
            .R_REF              13
            .R_INT16            16
            .R_OPERATOR         .SUB
            .R_STOP
        VM_SET                  13, .ARG0
        VM_POP                  1
        VM_ACTOR_MOVE_TO        12
        VM_STOP
1$:
        VM_SET_CONST            13, 0
        VM_ACTOR_MOVE_TO        12
        VM_STOP
_RIGHT_SCRIPT::
        VM_IF_CONST     .GTE    13, ^/18 * 8/, 1$, 0
        VM_RPN
            .R_REF              13
            .R_INT16            16
            .R_OPERATOR         .ADD
            .R_STOP
        VM_SET                  13, .ARG0
        VM_POP                  1
        VM_ACTOR_MOVE_TO        12
        VM_STOP
1$:
        VM_SET_CONST            13, ^/18 * 8/
        VM_ACTOR_MOVE_TO        12
        VM_STOP

_SCRIPT_2::
        VM_SET_CONST            12, 4
        VM_SET_CONST            13, 64
        VM_SET_CONST            14, 64
        VM_SET_CONST            15, ^/(.ACTOR_ATTR_H_FIRST | .ACTOR_ATTR_CHECK_COLL)/
        VM_INPUT_ATTACH         0x01, ___bank_KEYS_SCRIPT, _RIGHT_SCRIPT
        VM_INPUT_ATTACH         0x02, ___bank_KEYS_SCRIPT, _LEFT_SCRIPT
        VM_INPUT_ATTACH         0x04, ___bank_KEYS_SCRIPT, _UP_SCRIPT
        VM_INPUT_ATTACH         0x08, ___bank_KEYS_SCRIPT, _DOWN_SCRIPT

        VM_ACTOR_ACTIVATE       12
        VM_ACTOR_MOVE_TO        12

1$:        
        VM_PUSH                 60
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0  ; call wait_frames(), dispose 1 parameter on stack after
        VM_JUMP                 1$

        VM_STOP
