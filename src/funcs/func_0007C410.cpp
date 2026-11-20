int func_000256C0(unsigned int index, int argument);
void func_000681C0(int first, int second);

struct Object_000667D0 {
    void func_000667D0();
};

extern Object_000667D0 *data_00251F24;

struct Object_0007C250 {
    char unknown_00[0x48];
    int state;

    void func_0007C410();
};

// State handler 15 of the table at 0x20D2B8: once func_000256C0 (10, 0) says so, creates object 0x12af
// (func_000681C0 (1, 0)), moves to state 0x10 and runs func_000667D0 of the object at 0x251F24.
void Object_0007C250::func_0007C410()
{
    if (func_000256C0(10, 0)) {
        func_000681C0(1, 0);
        state = 0x10;
        data_00251F24->func_000667D0();
    }
}
