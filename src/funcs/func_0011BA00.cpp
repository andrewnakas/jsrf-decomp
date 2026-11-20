/* sym: ?func_00011C90@Object_0011AC40@@UAEXXZ = 0x0011BA00 */
struct Node {
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C90_5();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C90_7();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C90_9();
    virtual void func_00011C80_4(int argument);

    unsigned int flags;
    int id;
    unsigned int mask;
    float depth;
    int sortKey;
    char unknown_18[0xc];
    Node *parent;
    Node *child;
    Node *previous;
    Node *next;

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

// One of the four controller slots at data_00251E1C (0x40 bytes each).
struct Slot_001116E0 {
    int busy;
    char unknown_04[0x3c];
};

struct Game {
    void func_000127C0(int index, int value);
};

extern Game *data_0022FCE0;
extern Slot_001116E0 data_00251E1C[4];
extern int data_00251F20;

int func_00024650();
int func_0006F190();
void func_0006F5B0(int slot);

// The class whose table is at 0x1D7D00 (destructor 0x11AC40).
struct Object_0011AC40 : Node {
    virtual ~Object_0011AC40();
    virtual void func_00011C90();

    char unknown_34[0x10];
    int state;

    void func_0011B680();
};

// Slot 1: the state machine at +0x44. States 0 and 1 wait for func_00024650 (state 2), 2 goes to 3, 3 opens the
// current controller slot when it is free (state 5; otherwise func_0011B680), 5 waits for func_0006F190 (back to
// 3), 6 waits for func_00024650, sets game value 0x1af to 2 and goes to 7, and 7 closes the node.
void Object_0011AC40::func_00011C90()
{
    switch (state) {
    case 0:
        state = 2;
    case 1:
        if (func_00024650()) {
            state = 2;
        }
        break;
    case 2:
        state = 3;
        break;
    case 3:
        if (data_00251E1C[data_00251F20].busy == 0) {
            func_0006F5B0(data_00251F20);
            state = 5;
        } else {
            func_0011B680();
        }
        break;
    case 5:
        if (func_0006F190()) {
            state = 3;
        }
        break;
    case 6:
        if (func_00024650()) {
            data_0022FCE0->func_000127C0(0x1af, 2);
            state = 7;
        }
        break;
    case 7:
        func_00011BE0(this);
        func_00011C20(child);
        break;
    }
}
