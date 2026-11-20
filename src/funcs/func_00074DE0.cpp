/* sym: ?func_00011C90@Object_00074D60@@UAEXXZ = 0x00074DE0 */
struct Node {
    virtual ~Node();
    virtual void func_00011C90();

    char unknown_04[0x40];
};

struct Game {
    void func_000126D0(int value);
};

extern Game *data_0022FCE0;

int func_00024650();
void func_00024620(unsigned int mode, float rate);
void func_00118800();

// The class whose table is at 0x1CCCD8 (constructor 0x75A30, destructor 0x74D60): overrides slot 1.
struct Object_00074D60 : Node {
    virtual void func_00011C90();

    char unknown_44[0x54];
    int state;
};

// Slot 1: in state 0 or 5, once func_00024650 reports the fade done, func_000126D0(1) of the game and a new fade
// (rate 1/12); state 0 then also runs func_00118800 and moves to state 3.
void Object_00074D60::func_00011C90()
{
    switch (state) {
    case 0:
        if (func_00024650()) {
            data_0022FCE0->func_000126D0(1);
            func_00024620(0, 0.083333336f);
            func_00118800();
            state = 3;
        }
        break;
    case 5:
        if (func_00024650()) {
            data_0022FCE0->func_000126D0(1);
            func_00024620(0, 0.083333336f);
        }
        break;
    }
}
