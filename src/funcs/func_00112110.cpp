/* sym: ?func_00011C90@Object_001118F0@@UAEXXZ = 0x00112110 */
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

struct Object_001118F0 : Node {
    virtual ~Object_001118F0();
    virtual void func_00011C90();

    char unknown_034[0x128];
    int state;

    void func_00111C10();
};

// Slot 1 of the table at 0x1D27C8: state 0 goes to 1 and steps func_00111C10, state 1 steps it, state 2 runs
// func_00011BE0 and func_00011C20 on the node.
void Object_001118F0::func_00011C90()
{
    switch (state) {
    case 0:
        state = 1;
    case 1:
        func_00111C10();
        break;
    case 2:
        ((Node *)this)->func_00011BE0((Node *)this);
        ((Node *)this)->func_00011C20(((Node *)this)->child);
        break;
    }
}
