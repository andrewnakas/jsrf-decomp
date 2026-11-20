struct Game {
    void func_000126D0(int value);
    void func_000127C0(int index, int value);
    int func_000127E0(int index);
};

extern Game *data_0022FCE0;

struct Object_00039BE0 {
    void func_00039D80(int *values, unsigned int count);
};

extern Object_00039BE0 data_001EFFB0;

// The stage: values and their count at +0x8, the states to go on to at +0x14, +0x18 and +0x1c.
struct Stage_00056540 {
    char unknown_00[8];
    int *values;
    unsigned int count;
    char unknown_10[4];
    int first;
    int second;
    int third;
};

struct Object_0004ABA0 {
    char unknown_000[0x5c];
    int state;
    char unknown_060[0xf58];
    Stage_00056540 *stage;
    char unknown_fbc[0x34];
    int unknown_ff0;

    void func_00053FB0(int index);
    void func_000566D0();
};

// A state handler: once the game's entry 0x1a2 is set, runs the game's func_000126D0(0) and goes on by entry 0x1aa:
// 1 sets entry 0x199 to 0x14 and goes to the stage's +0x14, 2 to its +0x18, 3 sets +0xff0, entry 0x19a to 0 and 0x199
// to 0x20 and goes to its +0x1c; anything else hands the stage's values to func_00039D80 of 0x1EFFB0 and state 0xf.
void Object_0004ABA0::func_000566D0()
{
    if (data_0022FCE0->func_000127E0(0x1a2)) {
        switch (data_0022FCE0->func_000127E0(0x1aa)) {
        case 1:
            data_0022FCE0->func_000126D0(0);
            data_0022FCE0->func_000127C0(0x199, 0x14);
            func_00053FB0(stage->first);
            break;
        case 2:
            data_0022FCE0->func_000126D0(0);
            func_00053FB0(stage->second);
            break;
        case 3:
            data_0022FCE0->func_000126D0(0);
            unknown_ff0 = 1;
            data_0022FCE0->func_000127C0(0x19a, 0);
            data_0022FCE0->func_000127C0(0x199, 0x20);
            func_00053FB0(stage->third);
            break;
        default:
            data_0022FCE0->func_000126D0(0);
            data_001EFFB0.func_00039D80(stage->values, stage->count);
            state = 0xf;
            break;
        }
    }
}
