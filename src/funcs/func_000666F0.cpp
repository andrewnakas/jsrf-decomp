void func_00024600(int colour);
void func_00116670(int value);
void func_00118800();
int func_00119540(int first, int second, void *values);
int __stdcall func_00145560(void *counter);

// The fader (data_00251F24).
struct Object_000667D0 {
    int unknown_00;
    unsigned int flags;
    char unknown_08[0x90];
    int busy;
    char unknown_09c[4];
    int unknown_a0;
    unsigned int state;
    __int64 started;
    int sound;
    char unknown_b4[8];
    int unknown_bc;

    void func_000666F0(int first, int second);
};

// Unless already busy: starts a fade (func_00118800) and notes the time it started (func_00145560); with `second`
// it also starts sound 8/9 (func_00116670, func_00119540) and sets bit 2 of the state. Fades to black (bit 1 set) with
// `first`, to clear (bit 1 cleared) without; clears bit 0.
void Object_000667D0::func_000666F0(int first, int second)
{
    if (!busy) {
        flags |= 4;
        busy = 1;
        unknown_a0 = 0;
        unknown_bc = 0;
        func_00118800();
        if (second) {
            func_00116670(1);
            int values[3] = {0};
            sound = func_00119540(8, 9, values);
            state |= 4;
        }
        if (!first) {
            func_00024600(0);
            state &= ~2;
        } else {
            func_00024600(0xff000000);
            state |= 2;
        }
        state &= ~1;
        func_00145560(&started);
    }
}
