struct Object_00118CB0 {
    int func_001192E0(int group, int index, void *position);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The menu func_0013A340 runs (func_00139C00 is another of its members): the four controllers' buttons, one per
// byte, at +0x48.
struct Object_00139C00 {
    char unknown_000[0x48];
    unsigned int buttons;
    int mode;
    int value_50;
    char unknown_054[4];
    unsigned int count;
    unsigned int cursor;
    char unknown_060[0x250];
    int state;
    char unknown_2b4[0x104];
    int enabled[4];

    int func_0013A140();
};

// Clamps the cursor at +0x5c to 3 (with more than two entries in mode 0, else 0; the last entry in mode 1); then
// for each enabled controller: in mode 0, 0x40 and 0x80 move the cursor up and down (wrapping) with sound 3; 1 or 4
// set state 2 with sound 1 and return 1. Otherwise 0.
int Object_00139C00::func_0013A140()
{
    data_0022FCE0->func_000128C0(0x1deb);
    unsigned int last = 0;
    if (mode == 0 && count > 2) {
        last = 3;
    }
    if (value_50 == 0) {
        last = 0;
    }
    if (cursor > last) {
        cursor = last;
    }
    if (mode == 1) {
        cursor = count - 1;
    }
    for (unsigned int i = 0; i < 4; i++) {
        if (enabled[i]) {
            if (mode == 0) {
                if ((buttons >> (i * 8)) & 0x40) {
                    if (cursor == 0) {
                        cursor = last;
                    } else {
                        cursor--;
                    }
                    Object_00118CB0 *object = (Object_00118CB0 *)data_0022FCE0->func_000128C0(4);
                    if (object) {
                        object->func_001192E0(8, 3, 0);
                    }
                    return 0;
                }
                if ((buttons >> (i * 8)) & 0x80) {
                    if (cursor == last) {
                        cursor = 0;
                    } else {
                        cursor++;
                    }
                    Object_00118CB0 *object = (Object_00118CB0 *)data_0022FCE0->func_000128C0(4);
                    if (object) {
                        object->func_001192E0(8, 3, 0);
                    }
                    return 0;
                }
            }
            if ((buttons >> (i * 8)) & 5) {
                state = 2;
                Object_00118CB0 *object = (Object_00118CB0 *)data_0022FCE0->func_000128C0(4);
                if (object) {
                    object->func_001192E0(8, 1, 0);
                }
                return 1;
            }
        }
    }
    return 0;
}
