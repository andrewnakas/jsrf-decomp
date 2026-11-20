/* sym: ?func_00011C90@Object_000E7770@@UAEXXZ = 0x000E7770 */
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
    char unknown_34[0x10];
};

// The second base (table 0x1CE1B8), two slots.
struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

// The class whose tables are at 0x1CEDF0 (Node) and 0x1CEDE8 (Object_000C60C0 at +0x44).
struct Object_000E7770 : Node, Object_000C60C0 {
    virtual void func_00011C90();

    char unknown_048[0x74];
    int state;
};

// One handler per state, filled in by a dynamic initializer.
extern void (Object_000E7770::*data_002584A0[])();

// Slot 1: runs the handler of the current state.
void Object_000E7770::func_00011C90()
{
    (this->*data_002584A0[state])();
}
