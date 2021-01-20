#include "Sprite.h"

UINT8 sprites_pool[MAX_SPRITES];
UINT8 sprites_pool_next;
UINT8 hide_sprites = FALSE;

void init_sprite_pool() __banked
{
  UINT8 i;
  for (i = 0; i != MAX_SPRITES; i++)
  {
    UBYTE j = (i << 1);
    sprites_pool[MAX_SPRITES - i] = j;
    move_sprite(j, 0, 0);
    move_sprite(j + 1, 0, 0);
    set_sprite_prop(j, 0);
    set_sprite_prop(j + 1, 0);    
  }
  sprites_pool_next = MAX_SPRITES - 1;
}

UINT8 get_free_sprite() __banked
{
  return sprites_pool[sprites_pool_next--];
}

void release_sprite(UINT8 sprite_no) __banked
{
  sprites_pool[++sprites_pool_next] = sprite_no;
}
