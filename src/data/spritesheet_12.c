#pragma bank 255

// SpriteSheet: player-platform

#include "gbs_types.h"

const void __at(255) __bank_spritesheet_12;

// Right Idle

const metasprite_t spritesheet_12_metasprite_right_idle_1[]  = {
    {-13, 0,  0, 0}, {0, 8,  2, 0},
    {13, -8, 10, 0}, {0, 8, 12, 0},
    {metasprite_end}
};

const metasprite_t spritesheet_12_metasprite_right_idle_2[]  = {
    {-12, 0,  0, 0}, {0, 8,  2, 0},
    {12, -8, 10, 0}, {0, 8, 12, 0},
    {metasprite_end}
};

const metasprite_t spritesheet_12_metasprite_right_idle_3[]  = {
    {-13, 0,  0, 0}, {0, 8,  4, 0},
    {13, -8, 10, 0}, {0, 8, 12, 0},
    {metasprite_end}
};

// Left Idle

const metasprite_t spritesheet_12_metasprite_left_idle_1[]  = {
    {-13, 0,  2, 0x20}, {0, 8,  0, 0x20},
    {13, -8, 12, 0x20}, {0, 8, 10, 0x20},
    {metasprite_end}
};

const metasprite_t spritesheet_12_metasprite_left_idle_2[]  = {
    {-12, 0,  2, 0x20}, {0, 8,  0, 0x20},
    {12, -8, 12, 0x20}, {0, 8, 10, 0x20},
    {metasprite_end}
};

const metasprite_t spritesheet_12_metasprite_left_idle_3[]  = {
    {-13, 0,  4, 0x20}, {0, 8,  0, 0x20},
    {13, -8, 12, 0x20}, {0, 8, 10, 0x20},
    {metasprite_end}
};

// Right Walk

const metasprite_t spritesheet_12_metasprite_right_walk_1[]  = {
    {-13, 0,  0, 0}, {0, 8,  2, 0},
    {13, -8, 14, 0}, {0, 8, 16, 0},
    {metasprite_end}
};

const metasprite_t spritesheet_12_metasprite_right_walk_2[]  = {
    {-13, 0,  0, 0}, {0, 8,  2, 0},
    {13, -8, 18, 0}, {0, 8, 20, 0},
    {metasprite_end}
};

const metasprite_t spritesheet_12_metasprite_right_walk_3[]  = {
    {-13, 0,  0, 0}, {0, 8,  2, 0},
    {13, -8, 22, 0}, {0, 8, 24, 0},
    {metasprite_end}
};

// Left Walk

const metasprite_t spritesheet_12_metasprite_left_walk_1[]  = {
    {-13, 0,  2, 0x20}, {0, 8,  0, 0x20},
    {13, -8, 16, 0x20}, {0, 8, 14, 0x20},
    {metasprite_end}
};

const metasprite_t spritesheet_12_metasprite_left_walk_2[]  = {
    {-13, 0,  2, 0x20}, {0, 8,  0, 0x20},
    {13, -8, 20, 0x20}, {0, 8, 18, 0x20},
    {metasprite_end}
};

const metasprite_t spritesheet_12_metasprite_left_walk_3[]  = {
    {-13, 0,  2, 0x20}, {0, 8,  0, 0x20},
    {13, -8, 24, 0x20}, {0, 8, 22, 0x20},
    {metasprite_end}
};

// Right Jump

const metasprite_t spritesheet_12_metasprite_right_jump_1[]  = {
    {-13, 0,  0, 0}, {0, 8,  2, 0},
    {13, -8, 26, 0}, {0, 8, 28, 0},
    {metasprite_end}
};

// Left Jump

const metasprite_t spritesheet_12_metasprite_left_jump_1[]  = {
    {-13, 0,  2, 0x20}, {0, 8,  0, 0x20},
    {13, -8, 28, 0x20}, {0, 8, 26, 0x20},
    {metasprite_end}
};

// Climb

const metasprite_t spritesheet_12_metasprite_climb_1[]  = {
    {-13, 0,  6, 0}, {0, 8, 8, 0},
    {12, -8, 30, 0}, {0, 8, 32, 0},
    {metasprite_end}
};

const metasprite_t spritesheet_12_metasprite_climb_2[]  = {
    {-13, 0,  6, 0}, {0, 8, 8, 0},
    {12, -8, 32, 0x20}, {0, 8, 30, 0x20},
    {metasprite_end}
};

const metasprite_t * const spritesheet_12_metasprites[] = {
    // Right Idle
    spritesheet_12_metasprite_right_idle_1,
    spritesheet_12_metasprite_right_idle_1,
    spritesheet_12_metasprite_right_idle_1,
    spritesheet_12_metasprite_right_idle_3,
    spritesheet_12_metasprite_right_idle_1,
    spritesheet_12_metasprite_right_idle_1,
    spritesheet_12_metasprite_right_idle_1,
    spritesheet_12_metasprite_right_idle_2,
    // Left Idle
    spritesheet_12_metasprite_left_idle_1,
    spritesheet_12_metasprite_left_idle_1,
    spritesheet_12_metasprite_left_idle_1,
    spritesheet_12_metasprite_left_idle_3,
    spritesheet_12_metasprite_left_idle_1,
    spritesheet_12_metasprite_left_idle_1,
    spritesheet_12_metasprite_left_idle_1,
    spritesheet_12_metasprite_left_idle_2,
    // Right Walk
    spritesheet_12_metasprite_right_walk_1,
    spritesheet_12_metasprite_right_walk_2,
    spritesheet_12_metasprite_right_walk_3,
    // Left Walk
    spritesheet_12_metasprite_left_walk_1,
    spritesheet_12_metasprite_left_walk_2,
    spritesheet_12_metasprite_left_walk_3,
    // Right Jump
    spritesheet_12_metasprite_right_jump_1,
    // Left Jump
    spritesheet_12_metasprite_left_jump_1,   
    // Climb 
    spritesheet_12_metasprite_climb_1,   
    spritesheet_12_metasprite_climb_2,
};

const struct spritesheet_t spritesheet_12 = {
    .n_tiles = 34,
    .n_metasprites = 6,
    .metasprites = spritesheet_12_metasprites,
    .animations  = {
        // Idle
        { .start = 0,  .end = 0 }, // bottom
        { .start = 0,  .end = 7 }, // right
        { .start = 24, .end = 25 }, // top
        { .start = 8,  .end = 15 }, // left
        // Moving
        { .start = 23, .end = 23 }, // bottom
        { .start = 16, .end = 18 }, // right
        { .start = 22, .end = 22 }, // top
        { .start = 19, .end = 21 }, // left
    },
    .tiles = {
        0,0,0,0,3,3,12,15,20,27,36,63,41,62,51,61,47,63,39,61,55,44,51,46,125,67,212,171,65,127,63,63,0,0,0,0,248,248,52,204,10,246,197,123,191,255,126,130,254,110,254,2,182,110,182,110,254,2,206,182,249,255,15,15,0,0,0,0,248,248,52,204,10,246,197,123,191,255,126,130,254,110,254,2,146,110,254,110,254,2,206,182,249,255,15,15,0,0,0,0,7,7,8,15,22,25,33,62,96,127,224,255,32,63,41,54,41,54,41,54,85,106,149,234,126,125,3,3,0,0,0,0,224,224,16,240,104,152,132,124,4,252,4,252,4,252,36,220,36,220,36,220,170,86,169,215,158,254,96,96,0,0,0,0,0,0,14,9,30,17,44,51,93,99,63,49,78,127,116,79,92,103,63,63,31,31,63,63,62,33,63,63,0,0,0,0,176,208,104,248,8,248,36,220,102,158,101,159,247,13,247,13,254,62,252,252,252,252,190,190,175,177,191,191,0,0,0,0,3,3,14,13,30,17,44,51,61,59,39,63,59,39,63,35,31,30,47,63,39,63,19,31,14,15,7,7,0,0,0,0,176,208,104,248,8,248,148,236,54,206,53,207,127,131,127,129,254,30,254,254,248,248,112,176,120,136,248,248,0,0,0,0,15,15,30,17,62,33,109,83,114,127,206,191,244,143,253,142,119,120,63,63,63,63,110,118,79,113,127,127,0,0,0,0,176,208,104,248,12,252,22,238,55,205,181,79,255,3,254,14,255,31,255,249,166,186,28,28,0,0,0,0,0,0,0,0,7,7,15,12,14,9,29,19,30,17,55,57,74,127,229,254,243,254,191,255,191,255,248,152,124,68,60,60,0,0,0,0,176,208,232,120,8,248,20,236,180,204,220,228,124,164,250,38,222,98,190,194,254,254,248,248,156,228,252,252,0,0,0,0,0,0,127,127,248,151,248,151,243,159,124,127,236,243,255,224,191,240,191,255,254,158,124,68,60,60,0,0,0,0,0,0,0,0,191,223,111,253,23,237,54,206,180,76,254,2,254,14,255,31,255,249,102,122,28,28,0,0,0,0,0,0,7,7,15,15,31,31,35,63,96,127,227,188,243,188,231,248,95,96,127,126,103,127,59,39,58,38,30,18,30,30,0,0,240,240,255,255,255,249,219,253,14,254,12,252,12,252,4,252,6,254,130,126,186,254,254,254,36,60,60,60,0,0
    }
};
