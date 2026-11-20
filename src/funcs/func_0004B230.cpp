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
    char unknown_060[0x20c];
    int unknown_26c;
    int unknown_270;
    char unknown_274[0x2c];
    int unknown_2a0;
    char unknown_2a4[0xd14];
    Stage_00056540 *stage;

    void func_0004B230();
};

// State handler 38 of the table at 0x1F9888: -1 into +0x2a0, func_000FEA80 (0, the stage's +0x30 and +0x34, its entry
// at +0x14 for func_00043700 of 0x1FC724, 0), 60 into +0x26c and +0x270, func_00012730 (1) of the game, state 0x27.
void Object_0004ABA0::func_0004B230()
{
    Stage_00056540 *stage = this->stage;
    unknown_2a0 = -1;
    func_000FEA80(0, stage->unknown_30, stage->unknown_34, stage->sounds[data_001FC724.func_00043700()], 0);
    unknown_26c = 0x3c;
    unknown_270 = 0x3c;
    data_0022FCE0->func_00012730(1);
    state = 0x27;
}
