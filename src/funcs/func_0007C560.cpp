void func_0004EAF0();

struct Game {
    void func_000127C0(int first, int second);
    int func_000127E0(int id);
};

extern Game *data_0022FCE0;

struct Object_00039BE0 {
    int func_000149D0_1();
    int func_000149E0_1();
    int func_00039CA0();
};

extern Object_00039BE0 data_001EFFB0;

struct Object_0007C250 {
    char unknown_00[0x48];
    int state;

    void func_0007C560();
};

// State handler 19 of the table at 0x20D2B8: by func_000127E0 (0x1cc) of the game, state 0x38 (2), or func_0004EAF0 and
// state 0x1c (0), or (1) the same after passing the words of 0x1EFFB0 to func_000127C0 of the game as 6, 2 and 0x4d.
void Object_0007C250::func_0007C560()
{
    switch (data_0022FCE0->func_000127E0(0x1cc)) {
    case 0:
        func_0004EAF0();
        state = 0x1c;
        break;
    case 1:
        func_0004EAF0();
        data_0022FCE0->func_000127C0(6, data_001EFFB0.func_000149E0_1());
        data_0022FCE0->func_000127C0(2, data_001EFFB0.func_000149D0_1());
        data_0022FCE0->func_000127C0(3, 0x61);
        data_0022FCE0->func_000127C0(0x4d, data_001EFFB0.func_00039CA0());
        state = 0x1c;
        break;
    case 2:
        state = 0x38;
        break;
    }
}
