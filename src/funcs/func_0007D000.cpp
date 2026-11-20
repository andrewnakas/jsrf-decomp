struct Game {
    void func_000127C0(int index, int value);
};

extern Game *data_0022FCE0;

struct Object_0007C250 {
    char unknown_00[0x48];
    int state;

    void func_0007D000();
};

// State handler (table at 0x20D2B8): sets game value 0 to 20, clears game value 0x1a7 and goes to state 20.
void Object_0007C250::func_0007D000()
{
    data_0022FCE0->func_000127C0(0, 0x14);
    data_0022FCE0->func_000127C0(0x1a7, 0);
    state = 0x14;
}
