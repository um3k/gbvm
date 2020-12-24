#ifndef MUSIC_MANAGER_H
#define MUSIC_MANAGER_H

#include <gb/gb.h>

/**
 * Play music
 * 
 * @param index index of music in data_ptrs.h
 * @param loop if TRUE will infinitely loop the music
 */
void MusicPlay(UBYTE index, UBYTE loop) __nonbanked;

/**
 * Stop currently playing music
 */
void MusicStop() __banked;

/**
 * Update music player
 */
void MusicUpdate() __nonbanked;

/**
 * Play tone sound effect
 * 
 * @param tone tone of sound
 * @param frames number of frames to play for
 */
void SoundPlayTone(UWORD tone, UBYTE frames) __banked;

/**
 * Stop currently playing tone sound effect
 */
inline void SoundStopTone() {
    // stop tone on channel 1
    NR12_REG = 0x00;
}

/**
 * Play beep sound effect
 * 
 * @param pitch pitch of sound
 */
void SoundPlayBeep(UBYTE pitch) __banked;

/**
 * Play crash sound effect
 */
void SoundPlayCrash() __banked;

#endif
