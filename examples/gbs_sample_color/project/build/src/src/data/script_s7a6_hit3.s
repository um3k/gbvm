.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

ACTOR = -4

___bank_script_s7a6_hit3 = 255
.globl ___bank_script_s7a6_hit3

_script_s7a6_hit3::
        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 7
        VM_ACTOR_ACTIVATE       ACTOR

        ; Actor Set Spritesheet
        VM_ACTOR_SET_SPRITESHEET ACTOR, ___bank_spritesheet_4, _spritesheet_4

        ; Wait N Frames
        VM_PUSH_CONST           30
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Actor Hide
        VM_SET_CONST            ACTOR, 7
        VM_ACTOR_SET_HIDDEN     ACTOR, 1
        VM_ACTOR_DEACTIVATE     ACTOR

        ; Stop Script
        VM_STOP
