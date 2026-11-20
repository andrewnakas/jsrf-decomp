struct Game {
    void func_00012730(int value);
    void func_000127B0(int value);
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

void func_00024600(int color);
void func_00024620(unsigned int color, float rate);
void func_00116670(int value);
int func_001186D0(int value);

struct Object_000667D0 {
    int unknown_00;
    unsigned int flags;
    char unknown_08[0x90];
    int pending;
    char unknown_09c[8];
    unsigned int state;
    char unknown_0a8[8];
    int unknown_b0;

    void func_000667D0();
};

// Once a request is pending: clears it and bit 2 of +0x4, runs func_00116670(0) and func_001186D0 when bit 2 of +0xa4
// is set, the game's func_000127B0(0); then fades to black (func_00024600, func_00024620) unless object 0x12B0
// exists, in which case it sets bit 3 of +0xa4 and runs the game's func_00012730(1).
void Object_000667D0::func_000667D0()
{
    if (pending) {
        flags &= ~4;
        pending = 0;
        if (state & 4) {
            func_00116670(0);
            func_001186D0(unknown_b0);
        }
        data_0022FCE0->func_000127B0(0);
        state &= ~4;
        if (!data_0022FCE0->func_000128C0(0x12b0)) {
            func_00024600(0xff000000);
            func_00024620(0, 0.016666668f);
        } else {
            state |= 8;
            data_0022FCE0->func_00012730(1);
        }
    }
}
