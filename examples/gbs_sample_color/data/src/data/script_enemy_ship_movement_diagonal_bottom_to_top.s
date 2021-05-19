.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

ACTOR = -4

___bank_script_enemy_ship_movement_diagonal_bottom_to_top = 255
.globl ___bank_script_enemy_ship_movement_diagonal_bottom_to_top

_script_enemy_ship_movement_diagonal_bottom_to_top::
        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Actor Set Active
        VM_SET                  ACTOR, ^/(.ARG2 - 4)/

        ; Actor Move Relative
        VM_ACTOR_GET_POS        ACTOR
        VM_RPN
            .R_REF      ^/(ACTOR + 1)/
            .R_INT16    -640
            .R_OPERATOR .ADD
            .R_REF      ^/(ACTOR + 2)/
            .R_INT16    0
            .R_OPERATOR .ADD
            .R_STOP
        VM_SET                  ^/(ACTOR + 1 - 2)/, .ARG1
        VM_SET                  ^/(ACTOR + 2 - 2)/, .ARG0
        VM_POP                  2
        VM_SET_CONST            ^/(ACTOR + 3)/, 0
        VM_ACTOR_MOVE_TO        ACTOR

        ; Actor Set Active
        VM_SET                  ACTOR, ^/(.ARG2 - 4)/

        ; Actor Move Relative
        VM_ACTOR_GET_POS        ACTOR
        VM_RPN
            .R_REF      ^/(ACTOR + 1)/
            .R_INT16    768
            .R_OPERATOR .ADD
            .R_REF      ^/(ACTOR + 2)/
            .R_INT16    -768
            .R_OPERATOR .ADD
            .R_STOP
        VM_SET                  ^/(ACTOR + 1 - 2)/, .ARG1
        VM_SET                  ^/(ACTOR + 2 - 2)/, .ARG0
        VM_POP                  2
        VM_SET_CONST            ^/(ACTOR + 3)/, 0
        VM_ACTOR_MOVE_TO        ACTOR

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, .DIR_LEFT

        ; Actor Set Active
        VM_SET                  ACTOR, ^/(.ARG2 - 4)/

        ; Actor Set Active
        VM_SET                  ACTOR, ^/(.ARG2 - 4)/

        ; Actor Move Relative
        VM_ACTOR_GET_POS        ACTOR
        VM_RPN
            .R_REF      ^/(ACTOR + 1)/
            .R_INT16    768
            .R_OPERATOR .ADD
            .R_REF      ^/(ACTOR + 2)/
            .R_INT16    -768
            .R_OPERATOR .ADD
            .R_STOP
        VM_SET                  ^/(ACTOR + 1 - 2)/, .ARG1
        VM_SET                  ^/(ACTOR + 2 - 2)/, .ARG0
        VM_POP                  2
        VM_SET_CONST            ^/(ACTOR + 3)/, 0
        VM_ACTOR_MOVE_TO        ACTOR

        ; Actor Set Active
        VM_SET                  ACTOR, ^/(.ARG2 - 4)/

        ; Actor Move Relative
        VM_ACTOR_GET_POS        ACTOR
        VM_RPN
            .R_REF      ^/(ACTOR + 1)/
            .R_INT16    -2560
            .R_OPERATOR .ADD
            .R_REF      ^/(ACTOR + 2)/
            .R_INT16    0
            .R_OPERATOR .ADD
            .R_STOP
        VM_SET                  ^/(ACTOR + 1 - 2)/, .ARG1
        VM_SET                  ^/(ACTOR + 2 - 2)/, .ARG0
        VM_POP                  2
        VM_SET_CONST            ^/(ACTOR + 3)/, 0
        VM_ACTOR_MOVE_TO        ACTOR

        VM_POP                  4
        VM_RET_FAR
