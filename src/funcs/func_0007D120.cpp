void func_00025740(unsigned int index, int argument);
void func_0004EAF0();
void func_00024620(unsigned int color, float step);

struct Game {
    void func_000127C0(int first, int second);
    int func_000127E0(int id);
};

extern Game *data_0022FCE0;

struct Object_000667D0 {
    void func_000666F0(int first, int second);
};

extern Object_000667D0 *data_00251F24;

struct Object_0007C250 {
    char unknown_00[0x48];
    int state;

    void func_0007D120();
};

// State handler 59 of the table at 0x20D2B8: func_00025740 for (0x12, 1) and (10, 0); without 0x1bb set in the game,
// func_0004EAF0, func_000127C0 (0, 0x1c) and state 0x1c; with it, func_000127C0 (0, 10), state 0xa, a fade over 60
// frames (func_00024620) and func_000666F0 (0, 1) of the object at 0x251F24.
void Object_0007C250::func_0007D120()
{
    func_00025740(0x12, 1);
    func_00025740(10, 0);
    if (!data_0022FCE0->func_000127E0(0x1bb)) {
        func_0004EAF0();
        data_0022FCE0->func_000127C0(0, 0x1c);
        state = 0x1c;
    } else {
        data_0022FCE0->func_000127C0(0, 10);
        state = 0xa;
        func_00024620(0, 1.0f / 60.0f);
        data_00251F24->func_000666F0(0, 1);
    }
}
