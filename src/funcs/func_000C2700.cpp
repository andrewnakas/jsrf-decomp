struct Data_000C2700 {
    char unknown_00[3];
    char kind;
};

struct Object_000C20A0 {
    virtual void slot0();
    virtual void func_000C2700();

    char unknown_04[0x24];
    int value_28;
    char unknown_2c[4];
    unsigned int flags;
    int state;
    char unknown_38[0x40];
    Data_000C2700 *data;
};

// Virtual (slot 1 of the vtable at data_001CDC60, the class of func_000C20A0). Unless flag 1 at 0x30 is
// set: clears flag 2, then state 3 (clearing 0x28) when the data at 0x78 has kind 1, state 2 otherwise.
void Object_000C20A0::func_000C2700()
{
    if (!(flags & 1)) {
        flags &= ~2;
        if (data->kind == 1) {
            state = 3;
            value_28 = 0;
        } else {
            state = 2;
        }
    }
}
