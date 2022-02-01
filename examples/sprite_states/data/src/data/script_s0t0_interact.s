.module script_s0t0_interact

.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

.LOCAL_ACTOR = -4

___bank_script_s0t0_interact = 255
.globl ___bank_script_s0t0_interact

_script_s0t0_interact::
        VM_LOCK

        VM_RESERVE              4

        ; Actor Set Active
        VM_SET_CONST            .LOCAL_ACTOR, 0

        ; Actor Set Animation State
        VM_ACTOR_SET_ANIM_SET   .LOCAL_ACTOR, STATE_DEFAULT

        ; Stop Script
        VM_STOP
