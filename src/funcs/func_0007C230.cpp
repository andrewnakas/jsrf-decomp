struct Game {
    void func_000127C0(int index, int value);
};

extern Game *data_0022FCE0;

struct Object_0007C250 {
    char unknown_00[0x48];
    int state;

    void func_0007C230();
};

// State handler (table at 0x20D2B8): goes to state 12 and sets game value 0 to 6.
void Object_0007C250::func_0007C230()
{
    state = 12;
    data_0022FCE0->func_000127C0(0, 6);
}
