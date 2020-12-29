#ifndef MUSIC_MANAGER_H
#define MUSIC_MANAGER_H

#include <gb/gb.h>

extern UBYTE channel_mask;

inline void sound_init() {
    NR52_REG = 0x80; 
    NR51_REG = 0xFF;
    NR50_REG = 0x77;
}

/**
 * Play music
 * 
 * @param index index of music in data_ptrs.h
 * @param loop if TRUE will infinitely loop the music
 */
void music_play(UBYTE index, UBYTE loop) __nonbanked;

/**
 * Stop currently playing music
 */
void music_stop() __banked;

/** 
 * Mutes channels by mask
 * 
 * @param channels channel mask
 */
void music_mute(UBYTE channels) __nonbanked;

/**
 * Update music player
 */
void music_update() __nonbanked;

/**
 * Plays FX sound on given channel
 * 
 * @param frames sound length in frames
 * @param channel sound channel
 * @param data data to be written to sound registers
 */
void sound_play(UBYTE frames, UBYTE channel, UBYTE * data) __banked;

/**
 * Stops FX sound on given channel
 * 
 * @param channel sound channel
 */
void sound_stop(UBYTE channel) __banked;

#endif
