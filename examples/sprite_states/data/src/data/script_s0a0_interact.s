.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

ACTOR = -4

___bank_script_s0a0_interact = 255
.globl ___bank_script_s0a0_interact

_script_s0a0_interact::
        VM_LOCK

        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Actor Set Animation Set
        VM_ACTOR_SET_ANIM_SET   ACTOR, ANIM_SET_SURPRISED

        ; Wait N Frames
        VM_PUSH_CONST           30
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Actor Set Animation Set
        VM_ACTOR_SET_ANIM_SET   ACTOR, ANIM_SET_DEFAULT

        ; Stop Script
        VM_STOP
