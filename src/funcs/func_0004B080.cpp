struct Game {
    void func_00012730(int argument);
};

extern Game *data_0022FCE0;
extern int data_00251F20;

void func_0006F5B0(int index);

struct Object_0004ABA0 {
    char unknown_00[0x5c];
    int state;

    void func_0004B080();
};

// State handler 0x20 of the tables at 0x1F9888 and 0x1F9A68: func_00012730 of the game (1), shows text number
// 0x251F20 (func_0006F5B0) and moves to state 0x21.
void Object_0004ABA0::func_0004B080()
{
    data_0022FCE0->func_00012730(1);
    func_0006F5B0(data_00251F20);
    state = 0x21;
}
