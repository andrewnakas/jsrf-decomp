struct Game {
    int func_000127E0(int index);
};

// The five controller ports (64 bytes each): the buttons held, as a word.
struct Entry_00251DE8 {
    unsigned int buttons;
    char unknown_04[0x3c];
};

struct Object_00070850 {
    void func_00070960(int index);
};

// Member slot of the 0x1DE828 class (0x38 bytes).
struct Slot_001354C0 {
    int state;
    int choice;
    char unknown_08[4];
    int value_0c;
    char unknown_10[4];
    int value_14;
    char unknown_18[0x20];
};

// The repeat counts of a port's buttons 0x1000, 0x2000, 0x4000 and 0x8000.
struct Counts_001354C0 {
    unsigned int counts[4];
};

struct Object_00134880 {
    char unknown_000[0x54c];
    Slot_001354C0 slots[4];
    char unknown_62c[0xc0];
    Counts_001354C0 repeats[4];

    void func_001354C0(int port);
};

extern Game *data_0022FCE0;
extern Entry_00251DE8 data_00251DE8[];
extern int data_0022C6E4[];
extern int data_0022C7B8[][10];

// The page func_001354A0 gives: -1 when game value 0x1b6 is 3, else 0.
static inline int page()
{
    if (data_0022FCE0->func_000127E0(0x1b6) == 3) {
        return -1;
    }
    return 0;
}

// Member of the 0x1DE828 class: moves the port's choice (+0x550 of its slot) through 0-9 with buttons 0x2000 (back)
// and 0x1000 (on), or with their repeat counts above 25 (reset to 20), sound 3, then keeps data_0022C7B8's entry for
// the page and choice at +0x560 and -1 at +0x558; 0x8000 sets the slot's state to 4 and 0x4000 to 1 instead.
void Object_00134880::func_001354C0(int port)
{
    int row = page() + 1;
    int choice = slots[port].choice;
    unsigned int buttons = data_00251DE8[data_0022C6E4[port]].buttons;
    if (!(buttons & 0x2000) && repeats[port].counts[1] <= 25) {
        if (!(buttons & 0x1000) && repeats[port].counts[0] <= 25) {
            if (!(buttons & 0x8000) && repeats[port].counts[3] <= 25) {
                if ((buttons & 0x4000) || repeats[port].counts[2] > 25) {
                    if (repeats[port].counts[2] > 25) {
                        repeats[port].counts[2] = 20;
                    }
                    slots[port].state = 1;
                    ((Object_00070850 *)this)->func_00070960(3);
                }
                return;
            } else {
                if (repeats[port].counts[3] > 25) {
                    repeats[port].counts[3] = 20;
                }
                ((Object_00070850 *)this)->func_00070960(3);
                slots[port].state = 4;
                return;
            }
        } else {
            if (repeats[port].counts[0] > 25) {
                repeats[port].counts[0] = 20;
            }
            ((Object_00070850 *)this)->func_00070960(3);
            choice++;
            if (choice > 9) {
                choice = 0;
            }
            slots[port].choice = choice;
            slots[port].value_14 = data_0022C7B8[row][choice];
            slots[port].value_0c = -1;
        }
    } else {
        if (repeats[port].counts[1] > 25) {
            repeats[port].counts[1] = 20;
        }
        ((Object_00070850 *)this)->func_00070960(3);
        choice--;
        if (choice < 0) {
            choice = 9;
        }
        slots[port].choice = choice;
        slots[port].value_14 = data_0022C7B8[row][choice];
        slots[port].value_0c = -1;
    }
}
