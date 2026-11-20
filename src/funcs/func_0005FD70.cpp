/* sym: ?func_00011C90_2@Object_00062390@@UAEXXZ = 0x0005FD70 */
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

// The class whose table is at 0x1CB040: overrides slots 1 (62F50), 3 (64E30), 4 (5FD70), 6 (60200), 10 (5FD90), 12 (B3DE0), 13 (AECC0), 15 (B3DE0).
struct Object_00062390 : Node {
    virtual ~Object_00062390();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C80_4(int argument);

    char unknown_44[0x120];
    int state;
    char unknown_168[0x13bc];
    int kind;
};

// Slot 4: sets the state at +0x164 to 2 when it is 0, then runs slot 1.
void Object_00062390::func_00011C90_2()
{
    if (state == 0) {
        state = 2;
    }
    func_00011C90();
}
