#include "MusicManager.h"
#include "BankData.h"

#ifdef GBT_PLAYER
    #undef HUGE_TRACKER 
    #include "gbt_player.h"
#endif
#ifdef HUGE_TRACKER
    #undef GBT_PLAYER
    #include "hUGEDriver.h"
#endif

#include "data/data_ptrs.h"

#define MAX_MUSIC 255

UBYTE current_index = MAX_MUSIC;
UBYTE tone_frames = 0;
UBYTE channel_mask = 0x0f;
UBYTE sound_channel = 0;
#ifdef HUGE_TRACKER
UBYTE music_stopped = TRUE;
UBYTE current_track_bank = 0;
#endif

void MusicPlay(UBYTE index, UBYTE loop) __nonbanked {
    if (index != current_index) {
#ifdef GBT_PLAYER
        UBYTE _save = _current_bank;
        gbt_play(music_tracks[index].ptr, music_tracks[index].bank, 7);
        gbt_loop(loop);
        SWITCH_ROM_MBC1(_save);
#endif
#ifdef HUGE_TRACKER
        loop;
        UBYTE _save = _current_bank;
        current_track_bank = music_tracks[index].bank;
        SWITCH_ROM_MBC1(current_track_bank);
        __critical {
            hUGE_init(music_tracks[index].ptr);
            for (UBYTE i = HT_CH1; i <= HT_CH4; i++) 
                hUGE_mute_channel(i, HT_CH_PLAY);
        }
        SWITCH_ROM_MBC1(_save);
        music_stopped = FALSE;
#endif
        channel_mask = 0x0f;
        current_index = index;
    }
}

void MusicStop() __banked {
#ifdef GBT_PLAYER
    UBYTE _save = _current_bank;
    gbt_stop();
    SWITCH_ROM_MBC1(_save);
    current_index = MAX_MUSIC;
#endif
#ifdef HUGE_TRACKER
    music_stopped = TRUE;
    for (UBYTE i = HT_CH1; i <= HT_CH4; i++) 
        hUGE_mute_channel(i, HT_CH_MUTE);
#endif
}

void MusicMute(UBYTE channels) __nonbanked {
#ifdef GBT_PLAYER
    UBYTE _save = _current_bank;
    gbt_enable_channels(channels);
    SWITCH_ROM_MBC1(_save);
#endif
#ifdef HUGE_TRACKER
    for (UBYTE i = HT_CH1; i <= HT_CH4; i++, channels >>= 1) 
        hUGE_mute_channel(i, !(channels & 1));
#endif
}

void MusicUpdate() __nonbanked {
    if (tone_frames) {
        if (--tone_frames == 0) {
            SoundStop(sound_channel);
            MusicMute(channel_mask);
            sound_channel = 0;
        }
    }
#ifdef GBT_PLAYER 
    UBYTE _save = _current_bank;
    gbt_update();
    SWITCH_ROM_MBC1(_save);
#endif
#ifdef HUGE_TRACKER
    if (music_stopped) return;
    if (!current_track_bank) return;
    UBYTE _save = _current_bank;
    SWITCH_ROM_MBC1(current_track_bank);
    hUGE_dosound();
    SWITCH_ROM_MBC1(_save);
#endif
}

const UINT8 FX_REG_SIZES[]  = {5, 4, 5, 4};
const UINT8 FX_ADDR_LO[]    = {0x10, 0x16, 0x1a, 0x20};
const UINT8 channel_masks[] = {0x0e, 0x0d, 0x0b, 0x07};

void SoundPlay(UBYTE frames, UBYTE channel, UBYTE * data) __banked {
    if ((frames == 0) || (tone_frames)) return; // sound already playing or length in frames is zero.
    if ((channel) && (channel < 5)) { 
        sound_channel = channel--;
        MusicMute(channel_mask & channel_masks[channel]);
        UBYTE * reg = (UBYTE *)0xFF00 + FX_ADDR_LO[channel];
        for (UBYTE i = 0; i < FX_REG_SIZES[channel]; i++) *reg++ = *data++;
        tone_frames = frames;
    }
}

void SoundStop(UBYTE channel) __banked {
    switch (channel) {
        case 1: NR12_REG = 0x00; break; 
        case 2: NR22_REG = 0x00; break; 
        case 3: NR32_REG = 0x00; break;         // set volume 0 
        case 4: NR42_REG = 0x00; break;         // would that work?
    }
}
