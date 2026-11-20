void func_000FEB90(int value);

struct Game {
    void func_00012730(int argument);
};

extern Game *data_0022FCE0;

struct Stage_00056540 {
    char unknown_00[0x34];
    unsigned int unknown_34;
};

struct Object_0004ABA0 {
    char unknown_000[0x5c];
    int state;
    char unknown_060[0xf58];
    Stage_00056540 *stage;

    void func_0004D880();
    void func_00052CA0();
};

// State handler 60 of the table at 0x1F9888: for the stage's kinds 0 to 12 (at +0x34), func_000FEB90 (0x80000000 for
// kind 1, else 0), func_00012730 (1) of the game and state 0x3d; then func_0004D880.
void Object_0004ABA0::func_00052CA0()
{
    switch (stage->unknown_34) {
    case 0:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
        func_000FEB90(0);
        data_0022FCE0->func_00012730(1);
        state = 0x3d;
        break;
    case 1:
        func_000FEB90(0x80000000);
        data_0022FCE0->func_00012730(1);
        state = 0x3d;
        break;
    }
    func_0004D880();
}
