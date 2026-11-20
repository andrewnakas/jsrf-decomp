struct Object_00070850 {
    void func_00070960(int index);
};

struct Object_00120420 {
    char unknown_0000[0x1e0];
    int busy;
    char unknown_01e4[0x960];
    int cursor;
    char unknown_0b48[0x60];
    unsigned int held[4];
    char unknown_0bb8[0x2641];
    unsigned char shown_5;
    unsigned char lit_5;
    char unknown_31fb[2];
    unsigned char shown_3;
    unsigned char lit_3;
    unsigned char shown_2;
    unsigned char lit_2;
    unsigned char shown_1;
    unsigned char shown_0;
    unsigned char lit_0;
    unsigned char lit_1;
    unsigned char shown_4;
    unsigned char lit_4;

    int func_00132D60();
};

// Buttons held and newly pressed this frame.
extern unsigned int data_00251EE4;
extern unsigned int data_00251EE8;

// A six-entry menu with the cursor at 0xb44: while not busy (0x1e0), 0x4000 / 0x8000 (pressed, or held more than 25
// frames, which drops the count back to 20; counts at 0xba8) move the cursor up / down with sound 3, wrapping at 0 and
// 5. Every entry is shown plain, the cursor's lit; 2 or 8 cancels (sound 2, -1), 1 or 4 confirms (sound 0, 1); 0 else.
int Object_00120420::func_00132D60()
{
    if (busy == 0) {
        if (data_00251EE4 & 0x1000) {
            held[0]++;
        } else {
            held[0] = 0;
        }
        if (data_00251EE4 & 0x2000) {
            held[1]++;
        } else {
            held[1] = 0;
        }
        if (data_00251EE4 & 0x4000) {
            held[2]++;
        } else {
            held[2] = 0;
        }
        if (data_00251EE4 & 0x8000) {
            held[3]++;
        } else {
            held[3] = 0;
        }
        if ((data_00251EE8 & 0x4000) || held[2] > 25) {
            ((Object_00070850 *)this)->func_00070960(3);
            if (held[2] > 25) {
                held[2] = 20;
            }
            cursor--;
        }
        if ((data_00251EE8 & 0x8000) || held[3] > 25) {
            ((Object_00070850 *)this)->func_00070960(3);
            if (held[3] > 25) {
                held[3] = 20;
            }
            cursor++;
        }
        if (cursor > 5) {
            cursor = 0;
        }
        if (cursor < 0) {
            cursor = 5;
        }
    }
    shown_0 = 1;
    shown_1 = 1;
    shown_2 = 1;
    shown_3 = 1;
    shown_4 = 1;
    shown_5 = 1;
    if (busy == 0 && (data_00251EE8 & 0xa)) {
        ((Object_00070850 *)this)->func_00070960(2);
        return -1;
    }
    switch (cursor) {
    case 0:
        lit_0 = 1;
        shown_0 = 0;
        break;
    case 1:
        lit_1 = 1;
        shown_1 = 0;
        break;
    case 2:
        lit_2 = 1;
        shown_2 = 0;
        break;
    case 3:
        lit_3 = 1;
        shown_3 = 0;
        break;
    case 4:
        lit_4 = 1;
        shown_4 = 0;
        break;
    case 5:
        lit_5 = 1;
        shown_5 = 0;
        break;
    }
    if (busy == 0 && (data_00251EE8 & 5)) {
        ((Object_00070850 *)this)->func_00070960(0);
        return 1;
    }
    return 0;
}
