int func_000256C0(unsigned int index, int argument);

struct Object_000667D0 {
    void func_000667D0();
};

extern Object_000667D0 *data_00251F24;

struct Object_0007C250 {
    char unknown_00[0x48];
    int state;

    void func_0007CFB0();
};

// State handler 0x2d of the table at 0x20D2B8: once func_000256C0(0x13, 0) says so, goes to state 0x2e and runs
// func_000667D0 of the object at 0x251F24.
void Object_0007C250::func_0007CFB0()
{
    if (func_000256C0(0x13, 0)) {
        state = 0x2e;
        data_00251F24->func_000667D0();
    }
}
