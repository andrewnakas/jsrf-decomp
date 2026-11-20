// What 0x1FC724 is: func_00043700 gives the index of the current choice.
struct Object_00043700 {
    int func_00043700();
};

extern Object_00043700 data_001FC724;

// The block at +0x1040: two words at +0xec and +0xf0.
struct Info_0004C960 {
    char unknown_00[0xec];
    int unknown_ec;
    int unknown_f0;
};

// What func_0004CA20 copies from: a word at +0x34, one word per choice from +0x14 and three words from +0x38.
struct Setup_0004CA20 {
    char unknown_00[0x14];
    int values[8];
    int unknown_34;
    int unknown_38;
    int unknown_3c;
    int unknown_40;
};

// Object 9.
struct Object_0004ABA0 {
    char unknown_0000[0x1040];
    Info_0004C960 *info;
    char unknown_1044[0x10];
    int unknown_1054;
    int unknown_1058;
    int unknown_105c;
    int unknown_1060;
    int unknown_1064;
    int unknown_1068;
    int unknown_106c;

    void func_0004CA20(Setup_0004CA20 *setup);
};

// Copies the setup's word at +0x34 to +0x1054, its value for the current choice of 0x1FC724 (func_00043700) to
// +0x1058 and its words at +0x38-+0x40 to +0x1064-+0x106c; when the block at +0x1040 has a word at +0xec, that and the
// word after it go to +0x1060 and +0x105c.
void Object_0004ABA0::func_0004CA20(Setup_0004CA20 *setup)
{
    unknown_1054 = setup->unknown_34;
    unknown_1058 = setup->values[data_001FC724.func_00043700()];
    unknown_1064 = setup->unknown_38;
    unknown_1068 = setup->unknown_3c;
    unknown_106c = setup->unknown_40;
    if (info->unknown_ec) {
        unknown_1060 = info->unknown_ec;
        unknown_105c = info->unknown_f0;
    }
}
