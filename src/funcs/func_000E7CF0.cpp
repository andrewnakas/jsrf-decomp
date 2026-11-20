struct Motion_0005F060 {
    short unknown_00;
    short frames;
};

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

// The item at 0xd8 (12 bytes here).
struct Item_000162A0 {
    char unknown_00[0xc];
};

struct Object_00016200 {
    void func_000162A0(Item_000162A0 *item);
};

extern Object_00016200 data_0022FCE8;

// The class of func_000E7770 (Node and a chain link at 0x44); this is a handler of its table at 0x2584A0.
struct Object_000E7770 {
    char unknown_000[0x90];
    unsigned int flags;
    char unknown_094[0x3c];
    Motion_0005F060 *motion;
    float time;
    Item_000162A0 item;
    int value_e4;

    void func_000E7CF0();
};

// Entry 4 of the handlers at 0x2584A0: plays the motion at 0xd0 at half speed once and rewinds it past its last
// frame; then clears 0xe4 with the flag 0x100, else hands the item at 0xd8 to data_0022FCE8 (func_000162A0).
void Object_000E7770::func_000E7CF0()
{
    func_0005E030(motion, &time, 0.5f, 0);
    if (motion->frames - 1.0f < time) {
        time = 0.0f;
    }
    if (flags & 0x100) {
        value_e4 = 0;
    } else {
        data_0022FCE8.func_000162A0(&item);
    }
}
