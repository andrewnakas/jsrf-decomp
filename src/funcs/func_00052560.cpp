struct Object_00039BE0 {
    void func_00039D80(int *values, unsigned int count);
};

extern Object_00039BE0 data_001EFFB0;

struct Object_0004D8C0 {
    void func_0004D900(int kind, int id);
};

extern Object_0004D8C0 data_001FA05C;

struct Stage_00056540 {
    char unknown_00[8];
    int *values;
    unsigned int count;
    char unknown_10[4];
    int unknown_14;
};

struct Object_0004ABA0 {
    char unknown_000[0x5c];
    int state;
    char unknown_060[0x254];
    int unknown_2b4;
    char unknown_2b8[0xd00];
    Stage_00056540 *stage;

    void func_0004D880();
    void func_00052560();
};

// State handler 19 of the table at 0x1F9888: the stage's values to func_00039D80 of 0x1EFFB0, func_0004D900(9, stage +0x14)
// of 0x1FA05C, func_0004D880, then the state kept at +0x2b4.
void Object_0004ABA0::func_00052560()
{
    data_001EFFB0.func_00039D80(stage->values, stage->count);
    data_001FA05C.func_0004D900(9, stage->unknown_14);
    func_0004D880();
    state = unknown_2b4;
}
