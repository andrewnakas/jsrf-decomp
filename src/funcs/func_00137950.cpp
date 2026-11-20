/* sym: ?func_00011C90@Object_001377C0@@UAEXXZ = 0x00137950 */
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

struct Game {
    void func_000127C0(int index, int value);
};

extern Game *data_0022FCE0;

// The class whose table is at 0x1DEA20 (destructor 0x1377C0).
struct Object_001377C0 : Node {
    virtual ~Object_001377C0();
    virtual void func_00011C90();

    char unknown_34[0x10];
    int current;
    int last;
    unsigned int pending;

    void func_00137890();
};

// Slot 1: a pending state 4 runs func_00137890, sets game value 0x1bb to 0 and closes the node; a pending 5 sets it
// to 1 and closes the node; any other pending state becomes the current one (the old one kept in `last`). With no
// current state, state 1 is queued.
void Object_001377C0::func_00011C90()
{
    if (pending > 0) {
        switch (pending) {
        case 4:
            func_00137890();
            data_0022FCE0->func_000127C0(0x1bb, 0);
            func_00011BE0(this);
            func_00011C20(child);
            return;
        case 5:
            data_0022FCE0->func_000127C0(0x1bb, 1);
            func_00011BE0(this);
            func_00011C20(child);
            return;
        }
        last = current;
        current = pending;
        pending = 0;
    }
    if (current == 0) {
        pending = 1;
    }
}
