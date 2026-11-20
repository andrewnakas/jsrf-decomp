/* sym: ?func_00011C90_4@Object_0004ABA0@@UAEXXZ = 0x00052050 */
struct Node {
    Node(Node *owner, int id, unsigned int flags);
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
    char unknown_34[0x10];
};

// The class whose table is at 0x1CAAB0 (state tables 0x1F9888, 0x1F9A68, 0x1F9C48, 0x1F9E28, state at +0x5c).
struct Object_0004ABA0 : Node {
    virtual void func_00011C90_4();

    char unknown_044[0x18];
    unsigned int state;
    char unknown_060[0xf60];
    unsigned int delay;
    char unknown_fc4[0x74];
    int unknown_1038;

    void func_0004D880();
};

extern void (Object_0004ABA0::*data_001F9C48[])();

// Slot 7: clears +0x1038, counts the delay at +0xfc0 down (func_0004D880 on each step) and runs the handler of the
// state from the third state table (0x1F9C48), when it has one.
void Object_0004ABA0::func_00011C90_4()
{
    unknown_1038 = 0;
    if (delay > 0) {
        func_0004D880();
        delay--;
    }
    if (state < 0x77 && data_001F9C48[state]) {
        (this->*data_001F9C48[state])();
    }
}
