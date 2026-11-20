struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

void func_00025740(unsigned int index, int argument);

struct Object_0007C250 {
    char unknown_00[0x48];
    int state;

    void func_0007C020();
};

// State handler 2 of the table at 0x20D2B8: while object 0x12b0 does not exist, runs func_00025740 (10, 0) and moves
// to state 3.
void Object_0007C250::func_0007C020()
{
    if (!data_0022FCE0->func_000128C0(0x12b0)) {
        func_00025740(10, 0);
        state = 3;
    }
}
