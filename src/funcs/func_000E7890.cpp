struct Vector3 {
    float x;
    float y;
    float z;
};

// The object at data_00257CE8; func_00157F10 is the engine's.
struct Object_00157F10 {
    int func_00157F10(void *point, int value);
};

extern Object_00157F10 *data_00257CE8;

struct Object_0006DB80 {
    void func_0006DEB0(int sound, int stop);
};

extern Object_0006DB80 data_00251F78;

// The class of func_000E7770 (Node and a chain link at 0x44); this is a handler of its table at 0x2584A0.
struct Object_000E7770 {
    char unknown_000[0x78];
    Vector3 position;
    char unknown_084[0xc];
    unsigned int flags;
    char unknown_094[0x28];
    int state;
    char unknown_0c0[0x3c];
    int sound;

    void func_000E7890();
};

// Entry 0 of the handlers at 0x2584A0: unless func_00157F10 accepts the position with 500 (passed as the bits of
// 500.0f), drops the flag 0x100, stops the sound at 0xfc if there is one, and moves to state 1.
void Object_000E7770::func_000E7890()
{
    if (!data_00257CE8->func_00157F10(&position, 0x43fa0000)) {
        flags &= ~0x100;
        if (sound != -1) {
            data_00251F78.func_0006DEB0(sound, 1);
        }
        state = 1;
    }
}
