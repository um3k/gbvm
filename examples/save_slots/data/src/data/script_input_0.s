.include "vm.i"
.include "data/game_globals.i"
.include "macro.i"

.globl ___bank_scene_0, _scene_0

.area _CODE_255

ACTOR = -4

___bank_script_input_0 = 255
.globl ___bank_script_input_0

_script_input_0::
        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Text Menu
        VM_LOAD_TEXT            1
        .dw VAR_S1_MONEY
        .asciz "\001\001\003\003\002Save 1\nSave 2\nSave 3\n\243 %d\nTitle"
        VM_OVERLAY_CLEAR        0, 0, 10, 7, .UI_COLOR_WHITE, ^/(.UI_AUTO_SCROLL | .UI_DRAW_FRAME)/
        VM_OVERLAY_MOVE_TO      10, 18, 0
        VM_OVERLAY_MOVE_TO      10, 11, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/
        VM_CHOICE               VAR_S1_MENU, ^/(.UI_MENU_LAST_0)/, 5
            .MENUITEM           1, 1, 1, 5, 0, 2
            .MENUITEM           1, 2, 1, 5, 1, 3
            .MENUITEM           1, 3, 1, 5, 2, 4
            .MENUITEM           1, 4, 1, 5, 3, 5
            .MENUITEM           1, 5, 1, 5, 4, 0
        VM_OVERLAY_MOVE_TO      10, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/
        VM_OVERLAY_MOVE_TO      0, 18, 0

        ; Switch Variable
        ; case 0:
        VM_IF_CONST .NE         VAR_S1_MENU, 0, 1$, 0
        ; Load Scene
        VM_FADE_OUT             2
        VM_SET_CONST            ACTOR, 0
        VM_SET_CONST            ^/(ACTOR + 1)/, 1152
        VM_SET_CONST            ^/(ACTOR + 2)/, 1024
        VM_ACTOR_SET_POS        ACTOR
        VM_ACTOR_SET_DIR        ACTOR, .DIR_DOWN
        VM_RAISE                EXCEPTION_CHANGE_SCENE, 3
            IMPORT_FAR_PTR_DATA _scene_0

        VM_JUMP                 5$
1$:
        ; case 1:
        VM_IF_CONST .NE         VAR_S1_MENU, 1, 2$, 0
        ; Save Data to Slot 0
        VM_RAISE                EXCEPTION_SAVE, 1
            .SAVE_SLOT 0
        VM_PUSH_CONST           0
        VM_POLL_LOADED          .ARG0
        VM_IF_CONST .EQ         .ARG0, 1, 6$, 1

        ; Text Dialogue
        VM_LOAD_TEXT            0
        .asciz "Saved in Slot 1"
        VM_OVERLAY_CLEAR        0, 0, 20, 4, .UI_COLOR_WHITE, ^/(.UI_AUTO_SCROLL | .UI_DRAW_FRAME)/
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

6$:

        VM_JUMP                 5$
2$:
        ; case 2:
        VM_IF_CONST .NE         VAR_S1_MENU, 2, 3$, 0
        ; Save Data to Slot 1
        VM_RAISE                EXCEPTION_SAVE, 1
            .SAVE_SLOT 1
        VM_PUSH_CONST           0
        VM_POLL_LOADED          .ARG0
        VM_IF_CONST .EQ         .ARG0, 1, 7$, 1

        ; Text Dialogue
        VM_LOAD_TEXT            0
        .asciz "Saved in Slot 2"
        VM_OVERLAY_CLEAR        0, 0, 20, 4, .UI_COLOR_WHITE, ^/(.UI_AUTO_SCROLL | .UI_DRAW_FRAME)/
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

7$:

        VM_JUMP                 5$
3$:
        ; case 3:
        VM_IF_CONST .NE         VAR_S1_MENU, 3, 4$, 0
        ; Save Data to Slot 2
        VM_RAISE                EXCEPTION_SAVE, 1
            .SAVE_SLOT 2
        VM_PUSH_CONST           0
        VM_POLL_LOADED          .ARG0
        VM_IF_CONST .EQ         .ARG0, 1, 8$, 1

        ; Text Dialogue
        VM_LOAD_TEXT            0
        .asciz "Saved in Slot 3"
        VM_OVERLAY_CLEAR        0, 0, 20, 4, .UI_COLOR_WHITE, ^/(.UI_AUTO_SCROLL | .UI_DRAW_FRAME)/
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

8$:

        VM_JUMP                 5$
4$:
        ; default:
5$:

        ; Stop Script
        VM_STOP
