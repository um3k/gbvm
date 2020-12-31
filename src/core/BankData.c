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

void ReadBankedFarPtr(far_ptr_t * dest, unsigned char *ptr, UBYTE bank) __preserves_regs(b, c) __naked {
  dest; ptr; bank;
__asm
    ldh a, (__current_bank)
    ld  (#__save),a

    ldhl  sp, #6
    ld  a, (hl)
    ldh	(__current_bank),a
    ld  (#0x2000), a

    ldhl  sp, #2
    ld  a, (hl+)
    ld  e, a
    ld  a, (hl+)
    ld  d, a
    ld  a, (hl+)
    ld  h, (hl)
    ld  l, a

    .rept 2
      ld  a, (hl+)
      ld  (de), a
      inc de
    .endm
    ld  a, (hl)
    ld  (de), a

    ld  a, (#__save)
    ldh (__current_bank),a
    ld  (#0x2000), a
    ret
__endasm;  
}

UWORD ReadBankedUWORD(unsigned char *ptr, UBYTE bank) __preserves_regs(b, c) __naked {
  ptr; bank;
__asm
    ldh a, (__current_bank)
    ld  (#__save),a

    ldhl  sp,	#4
    ld  a, (hl-)
    ldh	(__current_bank),a
    ld  (#0x2000), a

    ld  a, (hl-)
    ld  l, (hl)
    ld  h, a
    ld  a, (hl+)
    ld  e, a
    ld  d, (hl)

    ld  a, (#__save)
    ldh (__current_bank),a
    ld  (#0x2000), a
    ret
__endasm;  
}

void MemcpyBanked(void* to, void* from, size_t n, UBYTE bank)  __naked {
  to; from; n; bank;
__asm
    ldh a, (__current_bank)
    ld  (#__save),a

    ldhl  sp,	#8
    ld  a, (hl)
    ldh	(__current_bank),a
    ld  (#0x2000), a

    pop bc
    call  _memcpy

    ld  a, (#__save)
    ldh (__current_bank),a
    ld  (#0x2000), a
    ld  h, b
    ld  l, c
    jp  (hl)
__endasm;  
}
