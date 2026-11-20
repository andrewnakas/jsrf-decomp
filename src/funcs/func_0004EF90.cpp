/* sym: ?func_00011C90@Object_0004EF90@@UAEXXZ = 0x0004EF90 */
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

// The class whose table is at 0x1CAAF8: overrides slots 1 (4EF90), 3 (4F9A0), 4 (AECC0), 7 (AECC0), 10 (AECC0).
struct Object_0004EF90 : Node {
    virtual ~Object_0004EF90();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();

    unsigned int state;
};

extern void (Object_0004EF90::*data_001FA008[])();

// Slot 1 of the table at 0x1CAAF8: runs the handler of the current state (21 states, table at 0x1FA008).
void Object_0004EF90::func_00011C90()
{
    if (state < 0x15) {
        (this->*data_001FA008[state])();
    }
}
