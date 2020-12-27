#ifndef MUSIC_MANAGER_H
#define MUSIC_MANAGER_H

#include <gb/gb.h>

extern UBYTE channel_mask;

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
 * Mutes channels by mask
 * 
 * @param channels channel mask
 */
void MusicMute(UBYTE channels) __nonbanked;

/**
 * Update music player
 */
void MusicUpdate() __nonbanked;

/**
 * Plays FX sound on given channel
 * 
 * @param frames sound length in frames
 * @param channel sound channel
 * @param data data to be written to sound registers
 */
void SoundPlay(UBYTE frames, UBYTE channel, UBYTE * data) __banked;

/**
 * Stops FX sound on given channel
 * 
 * @param channel sound channel
 */
void SoundStop(UBYTE channel) __banked;

#endif
