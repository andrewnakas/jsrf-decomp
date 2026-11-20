struct Game {
    void func_000126D0(int argument);
    void func_000127C0(int first, int second);
    int func_000127E0(int id);
};

extern Game *data_0022FCE0;

struct Object_0004ABA0 {
    char unknown_000[0x5c];
    int state;

    void func_0004C120();
};

// State handler 106 of the table at 0x1F9888: once func_000127E0 (0x1a1) of the game says so: with 0x19c set,
// func_000127C0 (0x199, 0x38) and state 0x63; else with 0x19d set, func_000127C0 (0x199, 10) and state 0x63; else
// func_000126D0 (0) and state 0x6b.
void Object_0004ABA0::func_0004C120()
{
    if (data_0022FCE0->func_000127E0(0x1a1)) {
        if (data_0022FCE0->func_000127E0(0x19c)) {
            data_0022FCE0->func_000127C0(0x199, 0x38);
            state = 0x63;
        } else if (data_0022FCE0->func_000127E0(0x19d)) {
            data_0022FCE0->func_000127C0(0x199, 10);
            state = 0x63;
        } else {
            data_0022FCE0->func_000126D0(0);
            state = 0x6b;
        }
    }
}
