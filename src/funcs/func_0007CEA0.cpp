void func_00025740(unsigned int index, int argument);

struct Game {
    int func_000127E0(int id);
    void func_000127C0(int first, int second);
};

extern Game *data_0022FCE0;

struct Object_0004D8C0 {
    void func_0004DAA0();
};

extern Object_0004D8C0 data_001FA05C;

struct Object_00039BE0 {
    void func_0003B790();
};

extern Object_00039BE0 data_001EFFB0;

struct Object_0007C250 {
    char unknown_00[0x44];
    int unknown_44;
    int state;

    void func_0007CEA0();
};

// State handler 43 of the table at 0x20D2B8: when func_000127E0 (0x19a) of the game says so, func_0004DAA0 of
// 0x1FA05C and func_00025740 for handlers 0x19 and 0x1a; then func_0003B790 of 0x1EFFB0,
// func_000127C0 (2, +0x44) of the game and state 0x14.
void Object_0007C250::func_0007CEA0()
{
    if (data_0022FCE0->func_000127E0(0x19a)) {
        data_001FA05C.func_0004DAA0();
        func_00025740(0x19, 0);
        func_00025740(0x1a, 0);
    }
    data_001EFFB0.func_0003B790();
    data_0022FCE0->func_000127C0(2, unknown_44);
    state = 0x14;
}
