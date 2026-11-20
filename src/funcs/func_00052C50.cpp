struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_00039BE0 {
    void func_00039D80(int *values, unsigned int count);
};

extern Object_00039BE0 data_001EFFB0;

struct Stage_00056540 {
    char unknown_00[8];
    int *values;
    unsigned int count;
};

struct Object_0004ABA0 {
    char unknown_000[0x5c];
    int state;
    char unknown_060[0x254];
    int unknown_2b4;
    char unknown_2b8[0xd00];
    Stage_00056540 *stage;
    char unknown_fbc[8];
    int unknown_fc4;

    void func_0004D880();
    void func_00052C50();
};

// State handler 57 of the tables at 0x1F9888 and 0x1F9A68: once the object whose id is at +0xfc4 is gone,
// func_0004D880, the stage's values to func_00039D80 of 0x1EFFB0, then the state kept at +0x2b4.
void Object_0004ABA0::func_00052C50()
{
    if (!data_0022FCE0->func_000128C0(unknown_fc4)) {
        func_0004D880();
        data_001EFFB0.func_00039D80(stage->values, stage->count);
        state = unknown_2b4;
    }
}
