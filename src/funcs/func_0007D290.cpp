void func_00025740(unsigned int index, int argument);
void func_00024620(unsigned int colour, float speed);

struct Game {
    void func_000127C0(int index, int value);
};

extern Game *data_0022FCE0;

struct Object_0007C250 {
    char unknown_00[0x48];
    int state;

    void func_0007D290();
};

// State handler 0x3f of the table at 0x20D2B8: runs action 10, sets the game's value 0 to 6, goes to state 6 and
// starts func_00024620 with colour 0 at 1/60.
void Object_0007C250::func_0007D290()
{
    func_00025740(0xa, 0);
    data_0022FCE0->func_000127C0(0, 6);
    state = 6;
    func_00024620(0, 0.016666668f);
}
