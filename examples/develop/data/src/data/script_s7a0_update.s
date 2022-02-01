.module script_s7a0_update

.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

.LOCAL_ACTOR = -4
.LOCAL_TMP1_WAIT_ARGS = -5

___bank_script_s7a0_update = 255
.globl ___bank_script_s7a0_update

_script_s7a0_update::
        VM_RESERVE              5

1$:
        ; Actor Set Active
        VM_SET_CONST            .LOCAL_ACTOR, 1

        ; Actor Move To
        VM_SET_CONST            ^/(.LOCAL_ACTOR + 1)/, 1024
        VM_SET_CONST            ^/(.LOCAL_ACTOR + 2)/, 1280
        VM_SET_CONST            ^/(.LOCAL_ACTOR + 3)/, ^/(.ACTOR_ATTR_CHECK_COLL | .ACTOR_ATTR_H_FIRST)/
        VM_ACTOR_MOVE_TO        .LOCAL_ACTOR

        ; Actor Set Active
        VM_SET_CONST            .LOCAL_ACTOR, 1

        ; Actor Move To
        VM_SET_CONST            ^/(.LOCAL_ACTOR + 1)/, 1024
        VM_SET_CONST            ^/(.LOCAL_ACTOR + 2)/, 2176
        VM_SET_CONST            ^/(.LOCAL_ACTOR + 3)/, ^/(.ACTOR_ATTR_CHECK_COLL | .ACTOR_ATTR_H_FIRST)/
        VM_ACTOR_MOVE_TO        .LOCAL_ACTOR

        ; Actor Set Active
        VM_SET_CONST            .LOCAL_ACTOR, 1

        ; Actor Move To
        VM_SET_CONST            ^/(.LOCAL_ACTOR + 1)/, 256
        VM_SET_CONST            ^/(.LOCAL_ACTOR + 2)/, 2176
        VM_SET_CONST            ^/(.LOCAL_ACTOR + 3)/, ^/(.ACTOR_ATTR_CHECK_COLL | .ACTOR_ATTR_H_FIRST)/
        VM_ACTOR_MOVE_TO        .LOCAL_ACTOR

        ; Actor Set Active
        VM_SET_CONST            .LOCAL_ACTOR, 1

        ; Actor Move To
        VM_SET_CONST            ^/(.LOCAL_ACTOR + 1)/, 256
        VM_SET_CONST            ^/(.LOCAL_ACTOR + 2)/, 1280
        VM_SET_CONST            ^/(.LOCAL_ACTOR + 3)/, ^/(.ACTOR_ATTR_CHECK_COLL | .ACTOR_ATTR_H_FIRST)/
        VM_ACTOR_MOVE_TO        .LOCAL_ACTOR

        ; Wait N Frames
        VM_SET_CONST            .LOCAL_TMP1_WAIT_ARGS, 1
        VM_INVOKE               b_wait_frames, _wait_frames, 0, .LOCAL_TMP1_WAIT_ARGS

        VM_JUMP                 1$
        ; Stop Script
        VM_STOP
