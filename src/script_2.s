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

_GRID_MOVE::
        ; event ID is already pushed onto vm thread stack
        VM_IF_CONST     .EQ     .ARG0, 0x01, _RIGHT_SCRIPT, 0
        VM_IF_CONST     .EQ     .ARG0, 0x02, _LEFT_SCRIPT, 0
        VM_IF_CONST     .EQ     .ARG0, 0x04, _UP_SCRIPT, 0
        VM_IF_CONST     .EQ     .ARG0, 0x08, _DOWN_SCRIPT, 0

        VM_IF_CONST     .NE     .ARG0, 0x10, 1$, 0                      ; NOT J_A?
        VM_SOUND_PLAY           42, 1, 0x1C,0x81,0xF3,0x73,0x86         ; BO-O-O-OW
        VM_STOP
1$:
        VM_IF_CONST     .NE     .ARG0, 0x20, 2$, 0                      ; NOT J_B?
        VM_SOUND_PLAY           3,  1, 0x24,0x81,0xF3,0x73,0x86         ; BLUP
2$:
        VM_STOP

_SCRIPT_2::
        VM_SET_CONST            12, 4
        VM_SET_CONST            13, 64
        VM_SET_CONST            14, 64
        VM_SET_CONST            15, ^/(.ACTOR_ATTR_H_FIRST | .ACTOR_ATTR_CHECK_COLL)/

        ; instead ot this:
;        VM_CONTEXT_PREPARE      1, ___bank_KEYS_SCRIPT, _RIGHT_SCRIPT
;        VM_INPUT_ATTACH         0x01, 1
;        VM_CONTEXT_PREPARE      2, ___bank_KEYS_SCRIPT, _LEFT_SCRIPT
;        VM_INPUT_ATTACH         0x02, 2
;        VM_CONTEXT_PREPARE      3, ___bank_KEYS_SCRIPT, _UP_SCRIPT
;        VM_INPUT_ATTACH         0x04, 3
;        VM_CONTEXT_PREPARE      4, ___bank_KEYS_SCRIPT, _DOWN_SCRIPT
;        VM_INPUT_ATTACH         0x08, 4

        ; we now able to use this:
        VM_CONTEXT_PREPARE      1, ___bank_KEYS_SCRIPT, _GRID_MOVE
        VM_INPUT_ATTACH         0x3f, 1         ; cursors, A, B

        VM_ACTOR_ACTIVATE       12
        VM_ACTOR_MOVE_TO        12

1$:        
        VM_PUSH                 60
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0  ; call wait_frames(), dispose 1 parameter on stack after
        VM_JUMP                 1$

        VM_STOP
