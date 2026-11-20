struct Game {
    void func_00012730(int which);
};

extern Game *data_0022FCE0;

struct Object_0004ABA0 {
    char unknown_0000[0x5c];
    int state;

    void func_0004B0B0();
};

int func_0006F190();

// State handler (table at 0x1F9888): goes to state 0x1f once func_0006F190 says object 0x12b0 is gone.
void Object_0004ABA0::func_0004B0B0()
{
    if (func_0006F190()) {
        data_0022FCE0->func_00012730(0);
        state = 0x1f;
    }
}
