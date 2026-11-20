struct Game {
    int func_000127E0(int index);
};

extern Game *data_0022FCE0;

struct Object_0007C250 {
    char unknown_00[0x48];
    int state;

    void func_0007C270();
};

// State handler (table at 0x20D2B8): takes the next state from game value 0.
void Object_0007C250::func_0007C270()
{
    state = data_0022FCE0->func_000127E0(0);
}
