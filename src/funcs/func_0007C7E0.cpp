struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_0007C250 {
    char unknown_00[0x48];
    int state;

    void func_0007C7E0();
};

// State handler (table at 0x20D2B8): goes to state 23 once object 0x128a is gone.
void Object_0007C250::func_0007C7E0()
{
    if (!data_0022FCE0->func_000128C0(0x128a)) {
        state = 23;
    }
}
