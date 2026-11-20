struct Object_00039BE0 {
    int func_0003A4F0();
};

extern Object_00039BE0 data_001EFFB0;
extern int data_00251F20;
extern int data_001FB93C[];

struct Object_00067030 {
    int values[4];
    int flags[4];

    void func_00067030(int slot, int mode, int value);
};

// When 0x1EFFB0 allows it, sets a slot (4: the one at 0x251F20) to the value of a mode from the table at 0x1FB93C, or
// to the given value for mode 3, and clears its flag.
void Object_00067030::func_00067030(int slot, int mode, int value)
{
    if (data_001EFFB0.func_0003A4F0()) {
        if (slot == 4) {
            slot = data_00251F20;
        }
        if (mode != 3) {
            values[slot] = data_001FB93C[mode];
            flags[slot] = 0;
        } else {
            values[slot] = value;
            flags[slot] = 0;
        }
    }
}
