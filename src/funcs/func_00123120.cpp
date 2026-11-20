struct Object_00070850 {
    void func_00070960(int index);
};

struct Object_00120420 {
    char unknown_0000[0x1cc];
    int step;
    char unknown_01d0[0x9e0];
    unsigned int held_up;
    unsigned int held_down;
    char unknown_0bb8[0x1ec];
    int choice;
    char unknown_0da8[0x2148];
    unsigned char chosen;
    unsigned char cancelled;
    char unknown_2ef2[0x26];
    unsigned char left;

    void func_00123120();
};

extern unsigned int data_00251EE4;
extern unsigned int data_00251EE8;

// Moves the choice at +0xda4 through -1 (-2 in step 9) .. 14 with buttons 0x8000 (up) and 0x4000 (down), pressed
// (data_00251EE8) or held over 25 frames (data_00251EE4, counted at +0xbb4 and +0xbb0, then repeating every 5),
// with sound 3 (func_00070960); then sets +0x2ef0 for a choice of 0 or more, else +0x2ef1 in step 9 and +0x2f18
// otherwise.
void Object_00120420::func_00123120()
{
    int first = step != 9 ? -1 : -2;
    if (data_00251EE4 & 0x4000) {
        held_up++;
    } else {
        held_up = 0;
    }
    if (data_00251EE4 & 0x8000) {
        held_down++;
    } else {
        held_down = 0;
    }
    if ((data_00251EE8 & 0x8000) || held_down > 25) {
        ((Object_00070850 *)this)->func_00070960(3);
        if (held_down > 25) {
            held_down = 20;
        }
        if (++choice > 14) {
            choice = first;
        }
    }
    if ((data_00251EE8 & 0x4000) || held_up > 25) {
        ((Object_00070850 *)this)->func_00070960(3);
        if (held_up > 25) {
            held_up = 20;
        }
        if (--choice < first) {
            choice = 14;
        }
    }
    if (choice < 0) {
        if (step == 9) {
            cancelled = 1;
        } else {
            left = 1;
        }
    } else {
        chosen = 1;
    }
}
