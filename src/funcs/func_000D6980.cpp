/* sym: ?func_000CD210@Object_000D6350@@UAEXXZ = 0x000D6980 */
struct Desc_000D6350 {
    char unknown_00[0x50];
    int value_50;
    char unknown_54[4];
    int value_58;
    char unknown_5c[4];
    float value_60;
};

// The base of the behaviours the factories of the table at 0x215D68 build; its slot 5 resets the common state.
struct Object_000CD1E0 {
    virtual void func_000CD210();

    Desc_000D6350 *desc;
};

// The behaviour func_000D6350 builds.
struct Object_000D6350 : Object_000CD1E0 {
    virtual void func_000CD210();

    char unknown_008[0xa0];
    float value_a8;
    float value_ac;
    float value_b0;
    float value_b4;
    char unknown_0b8[0x10];
    int value_c8;
    char unknown_0cc[0x30];
    float value_fc;
    float value_100;
    char unknown_104[0x1b8];
    int sounds[4];
    int value_2cc;
    int handles[4];
};

// Slot 5: runs Object_000CD1E0's, then clears 0x58 and 0x50 of the object it serves and sets its 0x60 to -0.01, the
// four floats at 0xa8 to -0.01, 0xfc and 0x100 to 1, 0xc8 to 0 and the sounds at 0x2bc, 0x2cc and the handles at 0x2d0
// to -1.
void Object_000D6350::func_000CD210()
{
    Object_000CD1E0::func_000CD210();
    desc->value_58 = 0;
    desc->value_50 = 0;
    desc->value_60 = -0.01f;
    value_b4 = -0.01f;
    value_b0 = -0.01f;
    value_ac = -0.01f;
    value_a8 = -0.01f;
    value_100 = 1.0f;
    value_fc = 1.0f;
    value_c8 = 0;
    value_2cc = -1;
    for (int i = 0; i < 4; i++) {
        sounds[i] = -1;
        handles[i] = -1;
    }
}
