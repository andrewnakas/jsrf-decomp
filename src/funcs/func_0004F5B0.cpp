struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_0004EF90 {
    char unknown_00[0x44];
    unsigned int state;

    void func_0004F5B0();
};

// State handler 15 of the table at 0x1FA008: goes to state 0x10 when object 9 is gone.
void Object_0004EF90::func_0004F5B0()
{
    if (!data_0022FCE0->func_000128C0(9)) {
        state = 0x10;
    }
}
