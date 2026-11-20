struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_0007C250 {
    char unknown_00[0x48];
    int state;

    void func_0007CE80();
};

// State handler (table at 0x20D2B8): goes to state 43 once object 0x8 is gone.
void Object_0007C250::func_0007CE80()
{
    if (!data_0022FCE0->func_000128C0(0x8)) {
        state = 43;
    }
}
