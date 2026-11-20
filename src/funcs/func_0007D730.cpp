// The pads (0x40 bytes each); flags 1 and 4 of the first byte are presses.
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

struct Object_0007C250 {
    char unknown_00[0x44];
    int step;
    char unknown_48[4];
    int time;
    char unknown_50[0xc];
    float frame;
    char unknown_60[0x20];
    Motion_0005F060 **motion;

    void func_0007D730();
};

// An entry of the update table at 0x20D3B8: steps the frame at +0x5c; a press (flags 5) of any of the four pads
// jumps to the last frame of the motion and step 3, reaching the last frame goes to step 2 (both clear +0x4c).
void Object_0007C250::func_0007D730()
{
    float next = frame + 1.0f;
    frame = next;
    if ((data_00251DE8[0].flags & 5) || (data_00251DE8[1].flags & 5) || (data_00251DE8[2].flags & 5) ||
        (data_00251DE8[3].flags & 5)) {
        step = 3;
        time = 0;
        frame = (*motion)->frames - 1.0f;
    } else if (next >= (*motion)->frames - 1.0f) {
        step = 2;
        time = 0;
        frame = (*motion)->frames - 1.0f;
    }
}
