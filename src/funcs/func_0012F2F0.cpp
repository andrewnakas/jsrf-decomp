struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_00070850 {
    void func_00070960(int index);
};

// The class of object 0x1de2.
struct Object_00120420 {
    char unknown_0000[0x1e0];
    int busy;
    char unknown_01e4[0x9c4];
    unsigned int held[4];
    char unknown_0bb8[0x2645];
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
};

// The class whose table is at 0x1DA350 (destructor 0x127E60).
struct Object_00127E60 {
    char unknown_00[0x48];
    int cursor;

    int func_0012F2F0();
};

// Buttons held and newly pressed this frame.
extern unsigned int data_00251EE4;
extern unsigned int data_00251EE8;

// A five-entry menu drawn by object 0x1de2, with the cursor at 0x48: while that object is not busy, 0x4000 / 0x8000
// (pressed, or held more than 25 frames, which drops its count back to 20) move the cursor up / down with sound 3,
// wrapping at 0 and 4. Every entry is shown plain, the cursor's lit; 1 or 4 confirms (sound 0, 1), 2 or 8 cancels
// (sound 2, -1); 0 else.
int Object_00127E60::func_0012F2F0()
{
    Object_00120420 *menu = (Object_00120420 *)data_0022FCE0->func_000128C0(0x1de2);
    int choice = cursor;
    if (menu->busy == 0) {
        if (data_00251EE4 & 0x1000) {
            menu->held[0]++;
        } else {
            menu->held[0] = 0;
        }
        if (data_00251EE4 & 0x2000) {
            menu->held[1]++;
        } else {
            menu->held[1] = 0;
        }
        if (data_00251EE4 & 0x4000) {
            menu->held[2]++;
        } else {
            menu->held[2] = 0;
        }
        if (data_00251EE4 & 0x8000) {
            menu->held[3]++;
        } else {
            menu->held[3] = 0;
        }
        if ((data_00251EE8 & 0x4000) || menu->held[2] > 25) {
            if (menu->held[2] > 25) {
                menu->held[2] = 20;
            }
            choice--;
            ((Object_00070850 *)menu)->func_00070960(3);
        }
        if ((data_00251EE8 & 0x8000) || menu->held[3] > 25) {
            if (menu->held[3] > 25) {
                menu->held[3] = 20;
            }
            choice++;
            ((Object_00070850 *)menu)->func_00070960(3);
        }
        if (choice > 4) {
            choice = 0;
        } else if (choice < 0) {
            choice = 4;
        }
    }
    cursor = choice;
    menu->shown_0 = 1;
    menu->shown_1 = 1;
    menu->shown_2 = 1;
    menu->shown_3 = 1;
    menu->shown_4 = 1;
    switch (cursor) {
    case 0:
        menu->lit_0 = 1;
        menu->shown_0 = 0;
        break;
    case 1:
        menu->lit_1 = 1;
        menu->shown_1 = 0;
        break;
    case 2:
        menu->lit_2 = 1;
        menu->shown_2 = 0;
        break;
    case 3:
        menu->lit_3 = 1;
        menu->shown_3 = 0;
        break;
    case 4:
        menu->lit_4 = 1;
        menu->shown_4 = 0;
        break;
    }
    if (menu->busy == 0) {
        if (!(data_00251EE8 & 5)) {
            if (data_00251EE8 & 0xa) {
                ((Object_00070850 *)menu)->func_00070960(2);
                return -1;
            }
        } else {
            ((Object_00070850 *)menu)->func_00070960(0);
            return 1;
        }
    }
    return 0;
}
