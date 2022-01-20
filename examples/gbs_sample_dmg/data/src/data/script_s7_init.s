.module script_s7_init

.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames, _fade_frames_per_step

.area _CODE_255

ACTOR = -4

___bank_script_s7_init = 255
.globl ___bank_script_s7_init
.CURRENT_SCRIPT_BANK == ___bank_script_s7_init

_script_s7_init::
        VM_LOCK

        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Actor Hide
        VM_SET_CONST            ACTOR, 0
        VM_ACTOR_SET_HIDDEN     ACTOR, 1
        VM_ACTOR_DEACTIVATE     ACTOR

        ; If Variable True
        VM_IF_CONST .GT         VAR_QUEST1, 0, 1$, 0
        VM_JUMP                 2$
1$:
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 1

        ; Actor Set Direction
        VM_ACTOR_SET_DIR        ACTOR, .DIR_UP

2$:

        ; If Variable True
        VM_IF_CONST .GT         VAR_QUEST2, 0, 3$, 0
        VM_JUMP                 4$
3$:
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 2

        ; Actor Set Direction
        VM_ACTOR_SET_DIR        ACTOR, .DIR_UP

4$:

        ; If Variable True
        VM_IF_CONST .GT         VAR_QUEST3, 0, 5$, 0
        VM_JUMP                 6$
5$:
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 3

        ; Actor Set Direction
        VM_ACTOR_SET_DIR        ACTOR, .DIR_UP

6$:

        ; If Variable True
        VM_IF_CONST .GT         VAR_QUEST4, 0, 7$, 0
        VM_JUMP                 8$
7$:
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 4

        ; Actor Set Direction
        VM_ACTOR_SET_DIR        ACTOR, .DIR_UP

8$:

        ; If Variable True
        VM_IF_CONST .GT         VAR_QUEST5, 0, 9$, 0
        VM_JUMP                 10$
9$:
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 5

        ; Actor Set Direction
        VM_ACTOR_SET_DIR        ACTOR, .DIR_UP

10$:

        ; If Variable True
        VM_IF_CONST .GT         VAR_QUEST6, 0, 11$, 0
        VM_JUMP                 12$
11$:
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 6

        ; Actor Set Direction
        VM_ACTOR_SET_DIR        ACTOR, .DIR_UP

12$:

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade In
        VM_SET_CONST_INT8       _fade_frames_per_step, 1
        VM_FADE_IN              1

        ; Wait For Input
        VM_INPUT_WAIT           240

        ; Pop Scene State
        VM_SET_CONST_INT8       _fade_frames_per_step, 3
        VM_FADE_OUT             1
        VM_SCENE_POP

        ; Stop Script
        VM_STOP
        ; Stop Script
        VM_STOP
