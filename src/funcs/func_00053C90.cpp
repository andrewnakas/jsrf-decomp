struct Game {
    void func_000126D0(int argument);
};

extern Game *data_0022FCE0;

void func_0004E9B0(int first, int second, int third);

struct Object_0004ABA0 {
    char unknown_00[0x4c];
    int unknown_4c;
    int unknown_50;
    int unknown_54;
    char unknown_58[0x4];
    int state;

    void func_0004D880();
    void func_00053C90();
};

// State handler 0x6b of the tables at 0x1F9888 and 0x1F9C48: func_000126D0 of the game (1), func_0004E9B0 with the
// words at +0x4c and +0x50 and 0, func_0004D880, then state 0x6c.
void Object_0004ABA0::func_00053C90()
{
    data_0022FCE0->func_000126D0(1);
    func_0004E9B0(unknown_4c, unknown_50, 0);
    func_0004D880();
    state = 0x6c;
}
