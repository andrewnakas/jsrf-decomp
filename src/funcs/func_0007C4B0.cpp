int func_000256A0(unsigned int index, int argument);

struct Game {
    int func_000127E0(int id);
};

extern Game *data_0022FCE0;

struct Object_000667D0 {
    void func_000666F0(int first, int second);
};

extern Object_000667D0 *data_00251F24;

struct Object_0007C250 {
    char unknown_00[0x48];
    int state;

    void func_0007C4B0();
};

// State handler 17 of the table at 0x20D2B8: once func_000256A0 runs handler 0x19 with 0, 1 or 3 as func_000127E0
// (0x1cc) of the game picks, state 0x12 and func_000666F0 (0, 1) of the object at 0x251F24.
void Object_0007C250::func_0007C4B0()
{
    int index = data_0022FCE0->func_000127E0(0x1cc);
    int values[3] = {0, 1, 3};
    if (func_000256A0(0x19, values[index])) {
        state = 0x12;
        data_00251F24->func_000666F0(0, 1);
    }
}
