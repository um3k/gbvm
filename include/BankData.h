#ifndef BANK_DATA_H
#define BANK_DATA_H

#include <gb/gb.h>

/**
 * Call set_bkg_data with data stored in banked memory (non-reentrant!)
 * 
 * @param i first tile to write to
 * @param l number of tiles to write
 * @param ptr memory address of tile data within bank
 * @param bank bank to read from
 */
void SetBankedBkgData(UBYTE i, UBYTE l, unsigned char *ptr, UBYTE bank);

/**
 * Call set_sprite_data with data stored in banked memory (non-reentrant!)
 * 
 * @param i first tile to write to
 * @param l number of tiles to write
 * @param ptr memory address of tile data within bank
 * @param bank bank to read from
 */
void SetBankedSpriteData(UBYTE i, UBYTE l, unsigned char *ptr, UBYTE bank);

/** 
 * Sets a rectangular region of Tile Map entries for the Background layer (non-reentrant!)
 * 
 * @param x      X Start position in Background Map tile coordinates. Range 0 - 31
 * @param y      Y Start position in Background Map tile coordinates. Range 0 - 31
 * @param w      Width of area to set in tiles. Range 0 - 31
 * @param h      Height of area to set in tiles.   Range 0 - 31
 * @param tiles  Pointer to source Tile Map data
 * @param bank   bank to read from
 */
void SetBankedBkgTiles(UINT8 x, UINT8 y, UINT8 w, UINT8 h, unsigned char *tiles, UBYTE bank);

/** 
 * Sets a rectangular region of Tile Map entries for the Window layer (non-reentrant!)
 * 
 * @param x      X Start position in Window Map tile coordinates. Range 0 - 31
 * @param y      Y Start position in Window Map tile coordinates. Range 0 - 31
 * @param w      Width of area to set in tiles. Range 0 - 31
 * @param h      Height of area to set in tiles.   Range 0 - 31
 * @param tiles  Pointer to source Tile Map data
 * @param bank   bank to read from
 */
void SetBankedWinTiles(UINT8 x, UINT8 y, UINT8 w, UINT8 h, unsigned char *tiles, UBYTE bank);


/**
 * Read UBYTE from banked memory location (non-reentrant!)
 * 
 * @param bank bank to read from
 * @param ptr memory address of data within bank
 * @return value stored in banked location
 */
UBYTE ReadBankedUBYTE(UBYTE bank, unsigned char *ptr);

/**
 * memcpy data from banked memory location (non-reentrant!)
 * 
 * @param bank bank to read from
 * @param to destination to write fetched data
 * @param from memory address of data within bank
 * @param n number of bytes to fetch from bank
 */
void MemcpyBanked(UBYTE bank, void* to, void* from, size_t n);

#endif
