#include "BankData.h"

#include <string.h>

#include "Scroll.h"

static UBYTE _save;

void SetBankedBkgData(UBYTE i, UBYTE l, unsigned char* ptr, UBYTE bank) __naked {
  i; l; ptr; bank;
__asm
    ldh a, (__current_bank)
    ld  (#__save),a

    ldhl  sp,	#6
    ld  a, (hl)
    ldh	(__current_bank),a
    ld  (#0x2000), a

    pop bc
    call  _set_bkg_data

    ld  a, (#__save)
    ldh (__current_bank),a
    ld  (#0x2000), a
    ld  h, b
    ld  l, c
    jp  (hl)
__endasm;  
}

void SetBankedSpriteData(UBYTE i, UBYTE l, unsigned char* ptr, UBYTE bank) __naked {
  i; l; ptr; bank;
__asm
    ldh a, (__current_bank)
    ld  (#__save),a

    ldhl  sp,	#6
    ld  a, (hl)
    ldh	(__current_bank),a
    ld  (#0x2000), a

    pop bc
    call  _set_sprite_data

    ld  a, (#__save)
    ldh (__current_bank),a
    ld  (#0x2000), a
    ld  h, b
    ld  l, c
    jp  (hl)
__endasm;  
}

void SetBankedBkgTiles(UINT8 x, UINT8 y, UINT8 w, UINT8 h, unsigned char *tiles, UBYTE bank) {
  x; y; w; h; tiles; bank;
__asm
    ldh a, (__current_bank)
    ld  (#__save),a

    ldhl  sp,	#8
    ld  a, (hl)
    ldh	(__current_bank),a
    ld  (#0x2000), a

    pop bc
    call  _set_bkg_tiles

    ld  a, (#__save)
    ldh (__current_bank),a
    ld  (#0x2000), a
    ld  h, b
    ld  l, c
    jp  (hl)
__endasm;  
}

void SetBankedWinTiles(UINT8 x, UINT8 y, UINT8 w, UINT8 h, unsigned char *tiles, UBYTE bank) {
  x; y; w; h; tiles; bank;
__asm
    ldh a, (__current_bank)
    ld  (#__save),a

    ldhl  sp,	#8
    ld  a, (hl)
    ldh	(__current_bank),a
    ld  (#0x2000), a

    pop bc
    call  _set_win_tiles

    ld  a, (#__save)
    ldh (__current_bank),a
    ld  (#0x2000), a
    ld  h, b
    ld  l, c
    jp  (hl)
__endasm;  
}

UBYTE ReadBankedUBYTE(UBYTE bank, unsigned char* ptr) __naked {
  ptr; bank;
__asm
    ldh a, (__current_bank)
    ld  (#__save),a

    ldhl  sp,	#2
    ld  a, (hl+)
    ldh	(__current_bank),a
    ld  (#0x2000), a

    ld  a, (hl+)
    ld  h, (hl)
    ld  l, a
    ld  e, (hl)

    ld  a, (#__save)
    ldh (__current_bank),a
    ld  (#0x2000), a
    ret
__endasm;  
}

void MemcpyBanked(UBYTE bank, void* to, void* from, size_t n) {
  _save = _current_bank;
  SWITCH_ROM_MBC1(bank);
  memcpy(to, from, n);
  SWITCH_ROM_MBC1(_save);
}
