.include "vm.i"
.include "data/game_globals.i"

.globl _pl_vel_y, b_wait_frames, _wait_frames, b_camera_shake_frames, _camera_shake_frames

.area _CODE_255

ACTOR = -4

___bank_script_custom_9 = 255
.globl ___bank_script_custom_9

_script_custom_9::
        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 0

        ; If Actor Relative To Actor
        VM_ACTOR_GET_POS        ACTOR
        VM_PUSH_VALUE           ^/(.ARG4 - 4)/
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_ACTOR_GET_POS        .ARG2
        VM_RPN
            .R_REF      ^/(ACTOR + 2 - 3)/
            .R_REF      .ARG0
            .R_OPERATOR .LT
            .R_STOP
        VM_IF_CONST .EQ         .ARG0, 0, 1$, 4
        ; Variable Set To True
        VM_PUSH_CONST           1
        VM_SET_INDIRECT         ^/(.ARG2 - 5)/, .ARG0
        VM_POP                  1

        ; Variable Decrement By 1
        VM_RPN
            .R_REF_IND  ^/(.ARG3 - 4)/
            .R_INT8     1
            .R_OPERATOR .SUB
            .R_STOP
        VM_SET_INDIRECT         ^/(.ARG3 - 5)/, .ARG0
        VM_POP                  1

        ; Actor Set Active
        VM_SET                  ACTOR, ^/(.ARG4 - 4)/

        ; Actor Set Collisions
        VM_ACTOR_SET_COLL_ENABLED ACTOR, 0

        ; Actor Set Active
        VM_SET                  ACTOR, ^/(.ARG4 - 4)/

        ; Actor Stop Update Script
        VM_ACTOR_TERMINATE_UPDATE ACTOR

        ; Actor Set Active
        VM_SET                  ACTOR, ^/(.ARG4 - 4)/

        ; Actor Set Spritesheet
        VM_ACTOR_SET_SPRITESHEET ACTOR, ___bank_spritesheet_6, _spritesheet_6

        ; Player Bounce
        VM_SET_CONST_INT16      _pl_vel_y, -8192

        ; Wait N Frames
        VM_PUSH_CONST           30
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Actor Hide
        VM_SET                  ACTOR, ^/(.ARG4 - 4)/
        VM_ACTOR_SET_HIDDEN     ACTOR, 1
        VM_ACTOR_DEACTIVATE     ACTOR

        VM_JUMP                 2$
1$:
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 0

        ; Actor Set Position
        VM_SET_CONST            ^/(ACTOR + 1)/, 6656
        VM_SET_CONST            ^/(ACTOR + 2)/, 1664
        VM_ACTOR_SET_POS        ACTOR

        ; Camera Shake
        VM_PUSH_CONST           30
        VM_PUSH_CONST           ^/(.CAMERA_SHAKE_X)/
        VM_INVOKE               b_camera_shake_frames, _camera_shake_frames, 2, .ARG1
2$:

        VM_POP                  4
        VM_RET_FAR
