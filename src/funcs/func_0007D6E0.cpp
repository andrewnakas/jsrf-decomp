/* sym: ?func_00011C90@Object_0007C250@@UAEXXZ = 0x0007D6E0 */
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

// The class whose table is at 0x1CCEF8: overrides slots 1 (7D6E0), 3 (7DA30).
struct Object_0007C250 : Node {
    virtual ~Object_0007C250();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);

    int step;
    int state;
    int unknown_4c[5];
    int unknown_60;
    int unknown_64[3];
    int unknown_70;
    int unknown_74;
    int unknown_78;
    int unknown_7c;
    int unknown_80;
};

extern void (Object_0007C250::*data_0020D3B8[])();

// Slot 1 of the table at 0x1CCEF8: runs the handler for the current step (table at 0x20D3B8) and advances the state.
void Object_0007C250::func_00011C90()
{
    (this->*data_0020D3B8[step])();
    state++;
}
