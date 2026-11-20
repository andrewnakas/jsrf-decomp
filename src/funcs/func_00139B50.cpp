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

struct Object_001379E0 {
    char unknown_000[0x44];
    int value_44;
    unsigned int buttons;
    int toggle;
    int values[4];
    char unknown_060[0x250];
    int state;

    void func_00139B50();
};

// Reacts to the buttons at +0x48 (the four bytes or-ed together): 0x0a sets state 3 and plays sound 2 of group 8
// on object 4; 0x40 or 0x80 flips the toggle at +0x4c, clears the four words after it and plays sound 3; 1 or 4
// sets +0x44 and passes 0 to func_00070960 (which never reads this).
void Object_001379E0::func_00139B50()
{
    if ((buttons | buttons >> 8 | buttons >> 16 | buttons >> 24) & 0xa) {
        state = 3;
        Object_00118CB0 *object = (Object_00118CB0 *)data_0022FCE0->func_000128C0(4);
        if (object) {
            object->func_001192E0(8, 2, 0);
        }
    } else if (((buttons | buttons >> 8 | buttons >> 16 | buttons >> 24) & 0x40)
               || ((buttons | buttons >> 8 | buttons >> 16 | buttons >> 24) & 0x80)) {
        toggle = toggle == 0;
        for (int i = 0; i < 4; i++) {
            values[i] = 0;
        }
        Object_00118CB0 *object = (Object_00118CB0 *)data_0022FCE0->func_000128C0(4);
        if (object) {
            object->func_001192E0(8, 3, 0);
        }
    } else if ((buttons | buttons >> 8 | buttons >> 16 | buttons >> 24) & 5) {
        value_44 = 1;
        ((Object_00070850 *)this)->func_00070960(0);
    }
}
