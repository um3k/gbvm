#include "VM_gameboy.h"
#include "Sprite.h"

void vm_show_sprites() __banked {
    hide_sprites = FALSE;
    SHOW_SPRITES;
}

void vm_hide_sprites() __banked {
    hide_sprites = TRUE;
    HIDE_SPRITES;
}
