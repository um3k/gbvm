.include "vm.i"
.include "data/game_globals.i"
.include "macro.i"

.globl b_wait_frames, _wait_frames, ___bank_scene_1, _scene_1

.area _CODE_255

ACTOR = -4

___bank_script_s0_init = 255
.globl ___bank_script_s0_init

_script_s0_init::
        VM_LOCK

        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade In
        VM_FADE_IN              1

        ; Text Dialogue
        VM_LOAD_TEXT            0
        .asciz "Welcome"
        VM_OVERLAY_CLEAR        0, 0, 20, 4, .UI_COLOR_WHITE, ^/(.UI_AUTO_SCROLL | .UI_DRAW_FRAME)/
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

BEGIN$:
        ; Text Menu
        VM_LOAD_TEXT            0
        .asciz "\001\001\003\003\002Game 1\nGame 2\nGame 3"
        VM_OVERLAY_CLEAR        0, 0, 10, 5, .UI_COLOR_WHITE, ^/(.UI_AUTO_SCROLL | .UI_DRAW_FRAME)/
        VM_OVERLAY_MOVE_TO      10, 18, 0
        VM_OVERLAY_MOVE_TO      10, 13, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/
        VM_CHOICE               VAR_S0_SAVE_SLOT, 0, 3
            .MENUITEM           1, 1, 1, 3, 0, 2
            .MENUITEM           1, 2, 1, 3, 1, 3
            .MENUITEM           1, 3, 1, 3, 2, 0
        VM_OVERLAY_MOVE_TO      10, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/
        VM_OVERLAY_MOVE_TO      0, 18, 0

        ; Switch Variable
        ; case 1:
        VM_IF_CONST .NE         VAR_S0_SAVE_SLOT, 1, 1$, 0
        ; If Variable True
        VM_PUSH_CONST           0
        VM_SAVE_PEEK            .ARG0, 0, 0, 0, 0
        VM_IF_CONST .EQ         .ARG0, 1, 5$, 1
        VM_JUMP                 NO_DATA$
        VM_JUMP                 6$
5$:
        VM_JUMP                 DATA$
6$:

        VM_JUMP                 4$
1$:
        ; case 2:
        VM_IF_CONST .NE         VAR_S0_SAVE_SLOT, 2, 2$, 0
        ; If Variable True
        VM_PUSH_CONST           0
        VM_SAVE_PEEK            .ARG0, 0, 0, 0, 1
        VM_IF_CONST .EQ         .ARG0, 1, 7$, 1
        VM_JUMP                 NO_DATA$
        VM_JUMP                 8$
7$:
        VM_JUMP                 DATA$
8$:

        VM_JUMP                 4$
2$:
        ; case 3:
        VM_IF_CONST .NE         VAR_S0_SAVE_SLOT, 3, 3$, 0
        ; If Variable True
        VM_PUSH_CONST           0
        VM_SAVE_PEEK            .ARG0, 0, 0, 0, 2
        VM_IF_CONST .EQ         .ARG0, 1, 9$, 1
        VM_JUMP                 NO_DATA$
        VM_JUMP                 10$
9$:
        VM_JUMP                 DATA$
10$:

        VM_JUMP                 4$
3$:
        ; default:
4$:

DATA$:
        ; Text Dialogue
        VM_LOAD_TEXT            1
        .dw VAR_S0_SAVE_SLOT
        .asciz "Data found for %d"
        VM_OVERLAY_CLEAR        0, 0, 20, 4, .UI_COLOR_WHITE, ^/(.UI_AUTO_SCROLL | .UI_DRAW_FRAME)/
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        ; Text Menu
        VM_LOAD_TEXT            0
        .asciz "\001\001\003\003\002Load\nClear"
        VM_OVERLAY_CLEAR        0, 0, 10, 4, .UI_COLOR_WHITE, ^/(.UI_AUTO_SCROLL | .UI_DRAW_FRAME)/
        VM_OVERLAY_MOVE_TO      10, 18, 0
        VM_OVERLAY_MOVE_TO      10, 14, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/
        VM_CHOICE               VAR_S0_LOAD_CLEAR_MENU_OPTION, 0, 2
            .MENUITEM           1, 1, 1, 2, 0, 2
            .MENUITEM           1, 2, 1, 2, 1, 0
        VM_OVERLAY_MOVE_TO      10, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/
        VM_OVERLAY_MOVE_TO      0, 18, 0

        ; Switch Variable
        ; case 1:
        VM_IF_CONST .NE         VAR_S0_LOAD_CLEAR_MENU_OPTION, 1, 11$, 0
        ; Text Dialogue
        VM_LOAD_TEXT            1
        .dw VAR_S0_SAVE_SLOT
        .asciz "Loading game %d"
        VM_OVERLAY_CLEAR        0, 0, 20, 4, .UI_COLOR_WHITE, ^/(.UI_AUTO_SCROLL | .UI_DRAW_FRAME)/
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        ; Switch Variable
        ; case 1:
        VM_IF_CONST .NE         VAR_S0_SAVE_SLOT, 1, 14$, 0
        ; Load Data from Slot 0
        VM_RAISE                EXCEPTION_LOAD, 1
            .SAVE_SLOT 0

        VM_JUMP                 17$
14$:
        ; case 2:
        VM_IF_CONST .NE         VAR_S0_SAVE_SLOT, 2, 15$, 0
        ; Load Data from Slot 1
        VM_RAISE                EXCEPTION_LOAD, 1
            .SAVE_SLOT 1

        VM_JUMP                 17$
15$:
        ; case 3:
        VM_IF_CONST .NE         VAR_S0_SAVE_SLOT, 3, 16$, 0
        ; Load Data from Slot 2
        VM_RAISE                EXCEPTION_LOAD, 1
            .SAVE_SLOT 2

        VM_JUMP                 17$
16$:
        ; default:
17$:

        VM_JUMP                 13$
11$:
        ; case 2:
        VM_IF_CONST .NE         VAR_S0_LOAD_CLEAR_MENU_OPTION, 2, 12$, 0
        ; Switch Variable
        ; case 1:
        VM_IF_CONST .NE         VAR_S0_SAVE_SLOT, 1, 18$, 0
        ; Clear Data in Slot 0
        VM_SAVE_CLEAR           0

        VM_JUMP                 21$
18$:
        ; case 2:
        VM_IF_CONST .NE         VAR_S0_SAVE_SLOT, 2, 19$, 0
        ; Clear Data in Slot 1
        VM_SAVE_CLEAR           1

        VM_JUMP                 21$
19$:
        ; case 3:
        VM_IF_CONST .NE         VAR_S0_SAVE_SLOT, 3, 20$, 0
        ; Clear Data in Slot 2
        VM_SAVE_CLEAR           2

        VM_JUMP                 21$
20$:
        ; default:
21$:

        ; Text Dialogue
        VM_LOAD_TEXT            1
        .dw VAR_S0_SAVE_SLOT
        .asciz "Game %d cleared"
        VM_OVERLAY_CLEAR        0, 0, 20, 4, .UI_COLOR_WHITE, ^/(.UI_AUTO_SCROLL | .UI_DRAW_FRAME)/
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        VM_JUMP                 13$
12$:
        ; default:
13$:

NO_DATA$:
        ; Text Dialogue
        VM_LOAD_TEXT            1
        .dw VAR_S0_SAVE_SLOT
        .asciz "No data found for \ngame %d"
        VM_OVERLAY_CLEAR        0, 0, 20, 4, .UI_COLOR_WHITE, ^/(.UI_AUTO_SCROLL | .UI_DRAW_FRAME)/
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        ; Text Menu
        VM_LOAD_TEXT            0
        .asciz "\001\001\003\003\002New\nBack"
        VM_OVERLAY_CLEAR        0, 0, 10, 4, .UI_COLOR_WHITE, ^/(.UI_AUTO_SCROLL | .UI_DRAW_FRAME)/
        VM_OVERLAY_MOVE_TO      10, 18, 0
        VM_OVERLAY_MOVE_TO      10, 14, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/
        VM_CHOICE               VAR_S0_NEW_BACK_MENU_OPTION, 0, 2
            .MENUITEM           1, 1, 1, 2, 0, 2
            .MENUITEM           1, 2, 1, 2, 1, 0
        VM_OVERLAY_MOVE_TO      10, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/
        VM_OVERLAY_MOVE_TO      0, 18, 0

        ; Switch Variable
        ; case 1:
        VM_IF_CONST .NE         VAR_S0_NEW_BACK_MENU_OPTION, 1, 22$, 0
        ; Text Dialogue
        VM_LOAD_TEXT            1
        .dw VAR_S0_SAVE_SLOT
        .asciz "Game %d started"
        VM_OVERLAY_CLEAR        0, 0, 20, 4, .UI_COLOR_WHITE, ^/(.UI_AUTO_SCROLL | .UI_DRAW_FRAME)/
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        ; Load Scene
        VM_FADE_OUT             2
        VM_SET_CONST            ACTOR, 0
        VM_SET_CONST            ^/(ACTOR + 1)/, 128
        VM_SET_CONST            ^/(ACTOR + 2)/, 1152
        VM_ACTOR_SET_POS        ACTOR
        VM_ACTOR_SET_DIR        ACTOR, .DIR_DOWN
        VM_RAISE                EXCEPTION_CHANGE_SCENE, 3
            IMPORT_FAR_PTR_DATA _scene_1

        VM_JUMP                 24$
22$:
        ; case 2:
        VM_IF_CONST .NE         VAR_S0_NEW_BACK_MENU_OPTION, 2, 23$, 0
        VM_JUMP                 24$
23$:
        ; default:
24$:

        VM_JUMP                 BEGIN$
        ; Stop Script
        VM_STOP
