void func_00024620(unsigned int color, float step);

struct Game {
    void func_000127C0(int first, int second);
};

extern Game *data_0022FCE0;

struct Info_00047080;

struct Object_00047110 {
    int func_000470C0(Info_00047080 *info);
};

extern Object_00047110 data_001F97A8;

struct Object_0007C250 {
    char unknown_00[0x48];
    int state;

    void func_0007D540();
};

// State handler 51 of the table at 0x20D2B8: func_000127C0 (0x1cb, 0) of the game; when func_000470C0 of 0x1F97A8
// says so, func_000127C0 (0, 0x3c) and state 0x3c, otherwise func_000127C0 (0, 6) and state 6; a fade over 60 frames
// (func_00024620) either way.
void Object_0007C250::func_0007D540()
{
    data_0022FCE0->func_000127C0(0x1cb, 0);
    if (data_001F97A8.func_000470C0(0)) {
        data_0022FCE0->func_000127C0(0, 0x3c);
        state = 0x3c;
        func_00024620(0, 1.0f / 60.0f);
    } else {
        data_0022FCE0->func_000127C0(0, 6);
        state = 6;
        func_00024620(0, 1.0f / 60.0f);
    }
}
