struct Object_00118CB0 {
    int func_001192E0(int group, int index, void *position);
};

struct Object_00070850 {
    void func_00070960(int index);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// A menu: the buttons at +0x48, a cursor over five rows at +0x50 and one over nine entries at +0x54, of which the
// mask at +0x60 says which are there.
struct Object_001379E0 {
    char unknown_000[0x44];
    int value_44;
    unsigned int buttons;
    char unknown_04c[4];
    int row;
    unsigned int entry;
    char unknown_058[8];
    unsigned int mask;

    void func_00139C00();
};

// Reacts to the buttons at +0x48 (the four bytes or-ed together): 0x0a clears +0x44 and plays sound 2 of group 8 on
// object 4; 0x40 and 0x80 move the row up and down (wrapping over 0-4) and play sound 3; 1 or 4 set +0x44 to 2,
// move the entry to the next one the mask has (from the current one, wrapping after 8) and pass 0 to
// func_00070960 (which never reads this).
void Object_001379E0::func_00139C00()
{
    if ((buttons | buttons >> 8 | buttons >> 16 | buttons >> 24) & 0xa) {
        value_44 = 0;
        Object_00118CB0 *object = (Object_00118CB0 *)data_0022FCE0->func_000128C0(4);
        if (object) {
            object->func_001192E0(8, 2, 0);
        }
        return;
    }
    if ((buttons | buttons >> 8 | buttons >> 16 | buttons >> 24) & 0x40) {
        if (row == 0) {
            row = 4;
        } else {
            row--;
        }
    } else if ((buttons | buttons >> 8 | buttons >> 16 | buttons >> 24) & 0x80) {
        if (row == 4) {
            row = 0;
        } else {
            row++;
        }
    } else {
        if ((buttons | buttons >> 8 | buttons >> 16 | buttons >> 24) & 5) {
            value_44 = 2;
            while (!(mask & (1 << entry))) {
                if (++entry > 8) {
                    entry = 0;
                }
            }
            ((Object_00070850 *)this)->func_00070960(0);
        }
        return;
    }
    Object_00118CB0 *object = (Object_00118CB0 *)data_0022FCE0->func_000128C0(4);
    if (object) {
        object->func_001192E0(8, 3, 0);
    }
}
