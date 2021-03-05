.include "vm.i"
.include "macro.i"
.include "data/game_globals.i"

.area _CODE_255

.globl ___bank_scene_4, _scene_4

___bank_script_s3_init = 255
.globl ___bank_script_s3_init

_script_s3_init::
        VM_LOCK

        ; Fade in
        VM_FADE_IN              .UI_MODAL

        ; Text Multiple Choice
        VM_LOAD_TEXT            0
        .asciz "\001\002New Game\nContinue"
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT         0, 0, .UI_ENABLE_MENU_ONECOL
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/
        VM_CHOICE               VAR_S3_TITLESCREEN_NEWGAME, ^/(.UI_MENU_LAST_0 | .UI_MENU_CANCEL_B)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/
        ; If Variable True
        VM_IF_CONST .EQ         VAR_S3_TITLESCREEN_NEWGAME, 1, 1$, 0
        VM_DATA_IS_SAVED        VAR_S3_TITLESCREEN_NEWGAME, 0
        VM_IF_CONST .EQ         VAR_S3_TITLESCREEN_NEWGAME, 0, 2$, 0

        ; VM_FADE_OUT             1     ; ! no need to fade out when loading !
        ; Load Game
        VM_RAISE                EXCEPTION_LOAD, 1
            .SAVE_SLOT 0

1$:
        VM_FADE_OUT             1
        ; New Game
        VM_PUSH_CONST           0
        VM_PUSH_CONST           1536
        VM_PUSH_CONST           1280
        VM_ACTOR_SET_POS        .ARG2
        VM_POP                  3
        VM_RAISE                EXCEPTION_CHANGE_SCENE, 3    ; sizeof(far_ptr_t) == 3
            IMPORT_FAR_PTR_DATA _scene_2

2$:
        VM_LOAD_TEXT            0
        .asciz "\020No save found!\nPress A"
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT         0, 0, 0
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/
        VM_JUMP                 1$
