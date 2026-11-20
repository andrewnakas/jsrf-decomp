int func_00119540(int group, int index, void *position);

// The pads (0x40 bytes each); flag 1 of the first byte is a press.
struct Entry_00251DE8 {
    unsigned char flags;
    char unknown_01[0x3f];
};

extern Entry_00251DE8 data_00251DE8[];

// A motion: its frame count at +0x2.
struct Motion_0005F060 {
    short unknown_00;
    short frames;
};

// A sprite with an alpha at +0x58.
struct Sprite_0007DAE0 {
    char unknown_00[0x58];
    float alpha;
};

// The sprites the title uses (+0x7c).
struct Sprites_0007DAE0 {
    char unknown_00[8];
    Sprite_0007DAE0 *prompt;
};

struct Object_0007C250 {
    char unknown_00[0x44];
    int step;
    char unknown_48[4];
    unsigned int time;
    int skipped;
    char unknown_54[8];
    float frame;
    float rate;
    char unknown_64[0x18];
    Sprites_0007DAE0 *sprites;
    Motion_0005F060 **motion;

    int func_0007D970();
    void func_0007DAE0();
};

// An entry of the update table at 0x20D3B8: a press on any of the four pads goes to step 4 (sound 8 / 0); after 0x1a4
// frames it goes to step 5 (noting the pads, func_0007D970) at the motion's last frame; either way +0x50 is set and
// the count cleared. Then pulses the alpha of the sprite at +0x8 by the rate at +0x60 between 0 and 1.
void Object_0007C250::func_0007DAE0()
{
    if ((data_00251DE8[0].flags & 1) || (data_00251DE8[1].flags & 1) || (data_00251DE8[2].flags & 1) ||
        (data_00251DE8[3].flags & 1)) {
        step = 4;
        time = 0;
        skipped = 1;
        func_00119540(8, 0, 0);
    } else if (time++ >= 0x1a4) {
        step = 5;
        func_0007D970();
        time = 0;
        skipped = 1;
        frame = (*motion)->frames - 1.0f;
    }
    sprites->prompt->alpha += rate;
    if (sprites->prompt->alpha > 1.0f) {
        sprites->prompt->alpha = 1.0f;
        rate = -1.0f / 60.0f;
    }
    if (sprites->prompt->alpha < 0.0f) {
        sprites->prompt->alpha = 0.0f;
        rate = 1.0f / 60.0f;
    }
}
