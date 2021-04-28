.include "vm.i"
.include "data/game_globals.i"
.include "macro.i"

.globl b_wait_frames, _wait_frames, ___bank_scene_0, _scene_0

.area _CODE_255

ACTOR = -4

___bank_script_s5_init = 255
.globl ___bank_script_s5_init

_script_s5_init::
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

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade In
        VM_FADE_IN              1

        ; Wait For Input
        VM_INPUT_WAIT           240

        ; Input Script Attach
        VM_CONTEXT_PREPARE      1, ___bank_script_input_0, _script_input_0
        VM_INPUT_ATTACH         128, 1

1$:
        ; Text Multiple Choice
        VM_LOAD_TEXT            0
        .asciz "\001\001 New Game\n Continue"
        VM_OVERLAY_CLEAR        0, 0, 20, 4, .UI_COLOR_WHITE, .UI_DRAW_FRAME
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/
        VM_CHOICE               VAR_NEWGAME, ^/(.UI_MENU_LAST_0 | .UI_MENU_CANCEL_B)/, 2
            .MENUITEM           1, 1, 0, 0, 0, 2
            .MENUITEM           1, 2, 0, 0, 1, 0
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        ; If Variable True
        VM_IF_CONST .GT         VAR_NEWGAME, 0, 2$, 0
        ; If Variable True
        VM_PUSH_CONST           0
        VM_SAVE_PEEK            .ARG0, 0, 0, 0, 0
        VM_IF_CONST .EQ         .ARG0, 1, 4$, 1
        ; Text Dialogue
        VM_LOAD_TEXT            0
        .asciz "No Save Data\nFound..."
        VM_OVERLAY_CLEAR        0, 0, 20, 4, .UI_COLOR_WHITE, .UI_DRAW_FRAME
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        VM_JUMP                 5$
4$:
        ; Load Data from Slot 0
        VM_RAISE                EXCEPTION_LOAD, 1
            .SAVE_SLOT 0

5$:

        VM_JUMP                 3$
2$:
        ; Load Scene
        VM_FADE_OUT             4
        VM_SET_CONST            ACTOR, 0
        VM_SET_CONST            ^/(ACTOR + 1)/, 3456
        VM_SET_CONST            ^/(ACTOR + 2)/, 3328
        VM_ACTOR_SET_POS        ACTOR
        VM_ACTOR_SET_DIR        ACTOR, .DIR_LEFT
        VM_RAISE                EXCEPTION_CHANGE_SCENE, 3
            IMPORT_FAR_PTR_DATA _scene_0

3$:

        VM_JUMP                 1$
        ; Stop Script
        VM_STOP
