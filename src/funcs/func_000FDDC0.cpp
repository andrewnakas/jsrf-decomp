struct Object_000FDDC0 {
    virtual void func_000FDDC0();

    char unknown_04[0x60];
    int state;
    int timer;
    char unknown_6c[0x14];
    unsigned int flags;
};

// Virtual (slot 16 of the vtables at data_001D08E0 and data_001D1BA8). Unless the state at 0x64 is 5: flag
// 0x8000000 at 0x80, timer at 0x68 = 0, state 4.
void Object_000FDDC0::func_000FDDC0()
{
    if (state != 5) {
        flags |= 0x8000000;
        timer = 0;
        state = 4;
    }
}
