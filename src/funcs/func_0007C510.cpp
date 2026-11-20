int func_000256C0(unsigned int index, int argument);

struct Game {
    int func_000127E0(int id);
};

extern Game *data_0022FCE0;

struct Object_0007C250 {
    char unknown_00[0x48];
    int state;

    void func_0007C510();
};

// State handler 18 of the table at 0x20D2B8: state 0x13 once func_000256C0 says so for handler 0x19 with 0, 1 or 3 as
// func_000127E0 (0x1cc) of the game picks.
void Object_0007C250::func_0007C510()
{
    int index = data_0022FCE0->func_000127E0(0x1cc);
    int values[3] = {0, 1, 3};
    if (func_000256C0(0x19, values[index]))
        state = 0x13;
}
