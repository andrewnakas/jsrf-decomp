struct Object_00070850 {
    void func_00070960(int index);
};

struct Object_00120420 {
    char unknown_0000[0x1e0];
    int busy;
    char unknown_01e4[0x9cc];
    unsigned int left;
    unsigned int right;
    char unknown_0bb8[0xc];
    int cursor;
    char unknown_0bc8[0x2300];
    unsigned char flags_2ec8;
    char unknown_2ec9;
    unsigned char flags_2eca;
    unsigned char flags_2ecb;
    unsigned char flags_2ecc;

    void func_001302B0();
    void func_001302F0();
};

// The buttons held (data_00251EE4) and pressed (data_00251EE8) this frame.
extern unsigned int data_00251EE4;
extern unsigned int data_00251EE8;

// Unless 0x1e0 is set: counts how long left (0x4000) and right (0x8000) are held; a press or a hold past 25 frames
// (which restarts the count at 20) moves the cursor at 0xbc4 right or left over 0-63 with sound 3 and runs
// func_001302B0. Then sets the four flags at 0x2ec8.
void Object_00120420::func_001302F0()
{
    if (!busy) {
        if (data_00251EE4 & 0x4000) {
            left++;
        } else {
            left = 0;
        }
        if (data_00251EE4 & 0x8000) {
            right++;
        } else {
            right = 0;
        }
        if (!(data_00251EE8 & 0x8000) && right <= 0x19) {
            if ((data_00251EE8 & 0x4000) || left > 0x19) {
                ((Object_00070850 *)this)->func_00070960(3);
                if (left > 0x19) {
                    left = 0x14;
                }
                if (--cursor < 0) {
                    cursor = 0x3f;
                }
                func_001302B0();
            }
        } else {
            ((Object_00070850 *)this)->func_00070960(3);
            if (right > 0x19) {
                right = 0x14;
            }
            if (++cursor >= 0x40) {
                cursor = 0;
            }
            func_001302B0();
        }
    }
    flags_2ec8 = 1;
    flags_2eca = 1;
    flags_2ecb = 1;
    flags_2ecc = 1;
}
