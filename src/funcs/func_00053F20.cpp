struct Game {
    void func_000126D0(int value);
    void func_000126F0(int value);
};

extern Game *data_0022FCE0;

void func_0004E9B0(int first, int second, int third);

struct Object_0004ABA0 {
    char unknown_000[0x4c];
    int unknown_4c;
    int unknown_50;
    char unknown_054[8];
    int state;

    void func_00053F20();
};

// State handler 0x75 of the table at 0x1F9888: func_000126D0(1) and func_000126F0(0) of the game,
// func_0004E9B0 with the words at +0x4c and +0x50, then state 0x76.
void Object_0004ABA0::func_00053F20()
{
    data_0022FCE0->func_000126D0(1);
    data_0022FCE0->func_000126F0(0);
    func_0004E9B0(unknown_4c, unknown_50, 0);
    state = 0x76;
}
