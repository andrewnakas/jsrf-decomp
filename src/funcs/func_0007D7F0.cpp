// The pads (0x40 bytes each); flag 1 of the first byte is a press.
struct Entry_00251DE8 {
    unsigned char flags;
    char unknown_01[0x3f];
};

extern Entry_00251DE8 data_00251DE8[];

struct Object_0007C250 {
    char unknown_00[0x44];
    int step;
    char unknown_48[0x4];
    unsigned int time;
    int skipped;

    void func_0007D7F0();
};

// Entry 2 of the update table at 0x20D3B8: moves to step 3 when a press of any of the four pads comes (+0x50 = 1)
// or after 0xb4 frames (+0x50 = 0).
void Object_0007C250::func_0007D7F0()
{
    if ((data_00251DE8[0].flags & 1) || (data_00251DE8[1].flags & 1) || (data_00251DE8[2].flags & 1) ||
        (data_00251DE8[3].flags & 1)) {
        time = 0;
        step = 3;
        skipped = 1;
    } else if (time++ >= 0xb4) {
        time = 0;
        step = 3;
        skipped = 0;
    }
}
