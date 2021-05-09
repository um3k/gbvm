.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

ACTOR = -4

___bank_script_s9_init = 255
.globl ___bank_script_s9_init

_script_s9_init::
        VM_LOCK

        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; If Variable True
        VM_IF_CONST .GT         VAR_QUEST7, 0, 1$, 0
        VM_JUMP                 2$
1$:
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 1

        ; Actor Set Animation Frame
        VM_SET_CONST            ^/(ACTOR + 1)/, 1
        VM_ACTOR_SET_ANIM_FRAME ACTOR

2$:

        ; If Variable True
        VM_IF_CONST .GT         VAR_QUEST8, 0, 3$, 0
        VM_JUMP                 4$
3$:
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 2

        ; Actor Set Animation Frame
        VM_SET_CONST            ^/(ACTOR + 1)/, 1
        VM_ACTOR_SET_ANIM_FRAME ACTOR

4$:

        ; If Variable True
        VM_IF_CONST .GT         VAR_QUEST9, 0, 5$, 0
        VM_JUMP                 6$
5$:
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 3

        ; Actor Set Animation Frame
        VM_SET_CONST            ^/(ACTOR + 1)/, 1
        VM_ACTOR_SET_ANIM_FRAME ACTOR

6$:

        ; If Variable True
        VM_IF_CONST .GT         VAR_QUEST10, 0, 7$, 0
        VM_JUMP                 8$
7$:
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 4

        ; Actor Set Animation Frame
        VM_SET_CONST            ^/(ACTOR + 1)/, 1
        VM_ACTOR_SET_ANIM_FRAME ACTOR

8$:

        ; If Variable True
        VM_IF_CONST .GT         VAR_QUEST11, 0, 9$, 0
        VM_JUMP                 10$
9$:
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 5

        ; Actor Set Animation Frame
        VM_SET_CONST            ^/(ACTOR + 1)/, 1
        VM_ACTOR_SET_ANIM_FRAME ACTOR

10$:

        ; Actor Hide
        VM_SET_CONST            ACTOR, 0
        VM_ACTOR_SET_HIDDEN     ACTOR, 1
        VM_ACTOR_DEACTIVATE     ACTOR

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade In
        VM_FADE_IN              1

        ; Wait For Input
        VM_INPUT_WAIT           240

        ; Pop Scene State
        VM_FADE_OUT             2
        VM_SCENE_POP

        ; Stop Script
        VM_STOP
        ; Stop Script
        VM_STOP
