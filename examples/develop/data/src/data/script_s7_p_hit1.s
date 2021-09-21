.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

ACTOR = -4

___bank_script_s7_p_hit1 = 255
.globl ___bank_script_s7_p_hit1

_script_s7_p_hit1::
        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; If Parameter 0 Equals 2
        VM_PUSH_CONST           0
        VM_GET_TLOCAL           .ARG0, 0
        VM_IF_CONST .EQ         .ARG0, 2, 1$, 1
        VM_JUMP                 2$
1$:
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 0

        ; Actor Emote
        VM_ACTOR_EMOTE          ACTOR, ___bank_emote_0, _emote_0

        ; Stop Script
        VM_STOP
2$:

        ; Stop Script
        VM_STOP
