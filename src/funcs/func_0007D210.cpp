int func_000256C0(unsigned int index, int argument);
void func_000681C0(int first, int second);

struct Game {
    void func_000127C0(int first, int second);
};

extern Game *data_0022FCE0;

struct Object_00039BE0 {
    void func_00039C80(int value);
    void func_00039C90(int value);
};

extern Object_00039BE0 data_001EFFB0;

struct Object_000667D0 {
    void func_000667D0();
};

extern Object_000667D0 *data_00251F24;

struct Object_0007C250 {
    char unknown_00[0x48];
    int state;

    void func_0007D210();
};

// State handler 61 of the table at 0x20D2B8: once func_000256C0 (10, 0) says so, state 0x3e, func_000127C0 (3, 0) of the
// game, func_00039C80 (0) and func_00039C90 (0) of 0x1EFFB0, func_000681C0 (0, 0) and func_000667D0 of the object at
// 0x251F24.
void Object_0007C250::func_0007D210()
{
    if (func_000256C0(10, 0)) {
        state = 0x3e;
        data_0022FCE0->func_000127C0(3, 0);
        data_001EFFB0.func_00039C80(0);
        data_001EFFB0.func_00039C90(0);
        func_000681C0(0, 0);
        data_00251F24->func_000667D0();
    }
}
