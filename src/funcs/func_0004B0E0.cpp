void func_000FEA80(int kind, int first, int second, int sound, int flags);

struct Game {
    void func_00012730(int argument);
};

extern Game *data_0022FCE0;

struct Object_00043700 {
    int func_00043700();
};

extern Object_00043700 data_001FC724;

struct Stage_00056540 {
    char unknown_00[0x14];
    int sounds[7];
    int unknown_30;
    int unknown_34;
};

struct Object_0004ABA0 {
    char unknown_000[0x5c];
    int state;
    char unknown_060[0x1f0];
    int unknown_250;
    int unknown_254;
    char unknown_258[0xd60];
    Stage_00056540 *stage;

    void func_0004B0E0();
};

// State handler 34 of the table at 0x1F9888: func_000FEA80 (1, the stage's +0x30 and +0x34, its entry at +0x14 for
// func_00043700 of 0x1FC724, 0), 60 into +0x250 and +0x254, func_00012730 (1) of the game, state 0x23.
void Object_0004ABA0::func_0004B0E0()
{
    Stage_00056540 *stage = this->stage;
    func_000FEA80(1, stage->unknown_30, stage->unknown_34, stage->sounds[data_001FC724.func_00043700()], 0);
    unknown_250 = 0x3c;
    unknown_254 = 0x3c;
    data_0022FCE0->func_00012730(1);
    state = 0x23;
}
