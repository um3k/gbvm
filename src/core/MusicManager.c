#include "MusicManager.h"
#include "BankData.h"

#ifdef GBT_PLAYER
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
    __critical {
        for (UBYTE i = HT_CH1; i <= HT_CH4; i++) 
            hUGE_mute_channel(i, HT_CH_MUTE);
        music_stopped = TRUE;
    }
#endif
}

void MusicUpdate() __nonbanked {
    if (tone_frames != 0) {
        tone_frames--;
        if (tone_frames == 0) SoundStopTone();
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

void SoundPlayTone(UWORD tone, UBYTE frames) __banked {
    tone_frames = frames;

    // enable sound
    NR52_REG = 0x80;

    // play tone on channel 1
    NR10_REG = 0x00;
    NR11_REG = (0x0U << 6U) | 0x01U;
    NR12_REG = (0x0FU << 4U) | 0x00U;
    NR13_REG = (tone & 0x00FF);
    NR14_REG = 0x80 | ((tone & 0x0700) >> 8U);

    // enable volume
    NR50_REG = 0x77;

    // enable channel 1
    NR51_REG |= 0x11;
}

void SoundPlayBeep(UBYTE pitch) __banked {
    // enable sound
    NR52_REG = 0x80;

    // play beep sound on channel 4
    NR41_REG = 0x01;
    NR42_REG = (0x0FU << 4U);
    NR43_REG = 0x20 | 0x08 | pitch;
    NR44_REG = 0x80 | 0x40;

    // enable volume
    NR50_REG = 0x77;

    // enable channel 4
    NR51_REG |= 0x88;

    // no delay
}

void SoundPlayCrash() __banked {
    // enable sound
    NR52_REG = 0x80;

    // play crash sound on channel 4
    NR41_REG = 0x01;
    NR42_REG = (0x0FU << 4U) | 0x02U;
    NR43_REG = 0x13;
    NR44_REG = 0x80;

    // enable volume
    NR50_REG = 0x77;

    // enable channel 4
    NR51_REG |= 0x88;

    // no delay
}
