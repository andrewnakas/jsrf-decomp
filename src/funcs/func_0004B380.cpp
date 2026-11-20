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
};

struct Object_0004ABA0 {
    char unknown_000[0x5c];
    int state;
    char unknown_060[0x228];
    int unknown_288;
    int unknown_28c;
    char unknown_290[0x10];
    int unknown_2a0;
    char unknown_2a4[0xd14];
    Stage_00056540 *stage;

    void func_0004B380();
};

// State handler 42 of the table at 0x1F9888: -1 into +0x2a0, func_000FEA80 (2, 0, the stage's +0x30, its entry at
// +0x14 for func_00043700 of 0x1FC724, 0), 60 into +0x288 and +0x28c, func_00012730 (1) of the game, state 0x2b.
void Object_0004ABA0::func_0004B380()
{
    Stage_00056540 *stage = this->stage;
    unknown_2a0 = -1;
    func_000FEA80(2, 0, stage->unknown_30, stage->sounds[data_001FC724.func_00043700()], 0);
    unknown_288 = 0x3c;
    unknown_28c = 0x3c;
    data_0022FCE0->func_00012730(1);
    state = 0x2b;
}
