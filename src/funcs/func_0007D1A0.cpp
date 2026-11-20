int func_000256C0(unsigned int index, int argument);
int func_00025680();
int func_000256A0(unsigned int index, int argument);
void func_00024620(unsigned int color, float step);

struct Object_000667D0 {
    void func_000666F0(int first, int second);
};

extern Object_000667D0 *data_00251F24;

struct Object_0007C250 {
    char unknown_00[0x48];
    int state;

    void func_0007D1A0();
};

// State handler 60 of the table at 0x20D2B8: when func_000256C0 (10, 0) says so, state 0x3d and a fade over 60 frames
// (func_00024620); otherwise, once func_00025680 allows, func_000256A0 (10, 0), the same and func_000666F0 (0, 1) of
// the object at 0x251F24.
void Object_0007C250::func_0007D1A0()
{
    if (func_000256C0(10, 0)) {
        state = 0x3d;
        func_00024620(0, 1.0f / 60.0f);
    } else if (!func_00025680()) {
        func_000256A0(10, 0);
        state = 0x3d;
        func_00024620(0, 1.0f / 60.0f);
        data_00251F24->func_000666F0(0, 1);
    }
}
