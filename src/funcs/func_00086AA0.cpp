struct Node {
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
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

// The family of tables at 0x1CD120, 0x1CD170, 0x1CD1C0 and 0x1CD210.
struct Object_00086960 : Node {
    virtual void func_00086AA0();

    char unknown_044[0x54];
    int unknown_98;
    char unknown_09c[0x88];
    unsigned int count;

    void func_00086730();
};

// Slot 17 of the tables at 0x1CD1C0 and 0x1CD210: runs func_00086730 and sets the field at +0x98 once the count at
// +0x124 is above zero.
void Object_00086960::func_00086AA0()
{
    func_00086730();
    if (count > 0) {
        unknown_98 = 1;
    }
}
