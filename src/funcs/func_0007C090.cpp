struct Game {
    void func_000129C0(int argument);
};

extern Game *data_0022FCE0;

int func_000256C0(unsigned int index, int argument);
int func_00025680();
int func_000256A0(unsigned int index, int argument);

struct Object_0007C250 {
    char unknown_00[0x48];
    int state;

    void func_0007C090();
};

// State handler 6 of the table at 0x20D2B8: func_000129C0 of the game (0); unless func_000256C0 (0x16, 0) says so,
// waits while func_00025680 says so and then runs func_000256A0 (0x16, 0); moves to state 7.
void Object_0007C250::func_0007C090()
{
    data_0022FCE0->func_000129C0(0);
    if (!func_000256C0(0x16, 0)) {
        if (func_00025680()) {
            return;
        }
        func_000256A0(0x16, 0);
    }
    state = 7;
}
