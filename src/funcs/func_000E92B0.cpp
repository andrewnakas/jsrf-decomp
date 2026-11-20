/* sym: ?func_000D7880@Object_000E7F50@@UAEXXZ = 0x000E92B0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

void func_000FEC30(int value, const Vector3 *position);

struct Object_0006DB80 {
    void func_0006DFC0(int key, const Vector3 *position);
};

extern Object_0006DB80 data_00251F78;

// The object at data_00257CE8 (func_00157F10 is the engine's); it also answers func_000C1D40.
struct Object_00157F10 {
    int func_000C1D40(int *effect, int *second, int *third);
};

extern Object_00157F10 *data_00257CE8;

// The object a behaviour serves (the owner type of the Object_000CC600 family).
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0xc];
    int value_5c;
    char unknown_60[0x3c];
    int value_9c;
    char unknown_a0[4];
    unsigned int flags;

    void func_000C5AD0(int amount);
};

// The base of the behaviours the factories of the table at 0x215D68 build.
struct Object_000CD1E0 {
    virtual void func_000D7880() = 0;

    Object_000C5B50 *desc;
    int state;
};

// The behaviour func_000E7F50 builds.
struct Object_000E7F50 : Object_000CD1E0 {
    virtual void func_000D7880();
    void func_000E89C0();

    char unknown_00c[0x5c];
    int value_68;
    char unknown_06c[0x78];
    int value_e4;
    char unknown_0e8[0x1c4];
    int effect;
    int value_2b0;
    int value_2b4;
    int sound;
};

// Slot 9: runs func_000E89C0; unless the served object has the flag 0x2000, either func_000C1D40 on data_00257CE8
// accepts the effect at 0x2ac (with 0x2b4 and 0x2b0) and the object gains 0x2000, state 6, func_000C5AD0(1) and 0x68 =
// 1, or func_000FEC30 gets the object's 0x9c and position; then the sound at 0x2b8 follows the position lifted by 10
// and 0xe4 takes the object's 0x5c.
void Object_000E7F50::func_000D7880()
{
    func_000E89C0();
    if (!(desc->flags & 0x2000)) {
        if (data_00257CE8->func_000C1D40(&effect, &value_2b4, &value_2b0)) {
            desc->flags |= 0x2000;
            state = 6;
            desc->func_000C5AD0(1);
            value_68 = 1;
        } else {
            func_000FEC30(desc->value_9c, &desc->position);
        }
        if (sound != -1) {
            Vector3 position = desc->position;
            position.y += 10.0f;
            data_00251F78.func_0006DFC0(sound, &position);
        }
        value_e4 = desc->value_5c;
    }
}
