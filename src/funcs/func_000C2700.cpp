struct Data_000C2700 {
    char unknown_00[3];
    char kind;
};

struct Pair_000C3100 {
    short first;
    short second;
};

// The base whose table is at 0x1CDCF8 (constructor func_000C2420, destructor func_000C2470); slot 9 is the
// destructor.
struct Object_000C2420 {
    Object_000C2420(Data_000C2700 *data);
    virtual void func_000C2630();
    virtual void func_000C2700();
    virtual void func_000C3800();
    virtual void func_000C30C0();
    virtual void func_000C3100();
    virtual void func_000C3140();
    virtual void func_000C31B0();
    virtual void func_000C3350();
    virtual void func_000C33C0();
    virtual ~Object_000C2420();
    virtual void func_000C2480();
    virtual void func_000C36F0();
    virtual void func_000C2FE0();
    virtual void func_000C2500();
    virtual void func_000C2560();
    virtual void func_000C25D0();
    virtual int func_000C2AA0();

    char unknown_04[0x24];
    int value_28;
    char unknown_2c[4];
    unsigned int flags;
    unsigned int state;
    char unknown_38[0x40];
    Data_000C2700 *data;
    Pair_000C3100 *pair;
    float value;
};

// Slot 1: unless flag 1 at 0x30 is set, clears flag 2, then state 3 (clearing 0x28) when the data at 0x78 has
// kind 1, state 2 otherwise.
void Object_000C2420::func_000C2700()
{
    if (!(flags & 1)) {
        flags &= ~2;
        if (data->kind == 1) {
            state = 3;
            value_28 = 0;
        } else {
            state = 2;
        }
    }
}
