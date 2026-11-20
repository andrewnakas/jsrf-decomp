int func_00024650();

struct Object_00039BE0 {
    void func_00039D80(int *values, unsigned int count);
};

extern Object_00039BE0 data_001EFFB0;

struct Stage_00056540 {
    char unknown_00[8];
    int *values;
    unsigned int count;
    char unknown_10[4];
    int unknown_14;
};

struct Object_0004ABA0 {
    char unknown_000[0xfb8];
    Stage_00056540 *stage;

    void func_00053FB0(int index);
    void func_00056540();
};

// State handler 0x3b of the table at 0x1F9888: when func_00024650 says so, hands the stage's values to
// func_00039D80 of the object at 0x1EFFB0 and runs func_00053FB0 with its word at +0x14.
void Object_0004ABA0::func_00056540()
{
    if (func_00024650()) {
        data_001EFFB0.func_00039D80(stage->values, stage->count);
        func_00053FB0(stage->unknown_14);
    }
}
