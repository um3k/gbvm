.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255



___bank_script_s0a2_interact = 255
.globl ___bank_script_s0a2_interact

_script_s0a2_interact::

        VM_LOCK

        ; Text Dialogue
        VM_LOAD_TEXT            0
        .asciz "It's dangerous to\ngo without docs."
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT         0, 0, 0
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        ; Emote
        VM_PUSH                 3
        VM_ACTOR_EMOTE          .ARG0, ___bank_spritesheet_1, _spritesheet_1
        VM_POP                  1

        ; Text Dialogue
        VM_LOAD_TEXT            0
        .asciz "Check out\ngbstudio.dev/docs"
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT         0, 0, 0
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/
        ; Stop Script
        VM_STOP
