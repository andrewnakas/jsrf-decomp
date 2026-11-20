int func_000FEC10();

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
    char unknown_060[0x254];
    int unknown_2b4;
    char unknown_2b8[0xd00];
    Stage_00056540 *stage;

    void func_0004B610();
};

// State handler 0x3d of the tables at 0x1F9888 and 0x1F9A68: once func_000FEC10 says so, moves to the state kept at
// +0x2b4, hands the stage's values to func_00039D80 of 0x1EFFB0 and runs func_00012730 of the game (0).
void Object_0004ABA0::func_0004B610()
{
    if (func_000FEC10()) {
        state = unknown_2b4;
        data_001EFFB0.func_00039D80(stage->values, stage->count);
        data_0022FCE0->func_00012730(0);
    }
}
