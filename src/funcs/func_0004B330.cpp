void func_000FE5E0(int index);

struct Game {
    void func_00012730(int argument);
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
    char unknown_060[0x23c];
    int unknown_29c;
    char unknown_2a0[0x14];
    int unknown_2b4;
    char unknown_2b8[0xd00];
    Stage_00056540 *stage;

    void func_0004B330();
};

// State handler 41 of the tables at 0x1F9888 and 0x1F9A68: once +0x29c is set, func_000FE5E0 (0), func_00012730 (0) of the
// game, the state kept at +0x2b4 and the stage's values to func_00039D80 of 0x1EFFB0.
void Object_0004ABA0::func_0004B330()
{
    if (unknown_29c) {
        func_000FE5E0(0);
        data_0022FCE0->func_00012730(0);
        state = unknown_2b4;
        data_001EFFB0.func_00039D80(stage->values, stage->count);
    }
}
