/* sym: ?func_00011C90_1@Object_000E6E80@@UAEXXZ = 0x000E7540 */
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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};

// The child of Node whose table is at 0x1CEDA0.
struct Object_000E6E80 : Node {
    char unknown_40[0x60];
    unsigned int flags_a0;

    void func_000E6E80();
    virtual void func_00011C90_1();
};

// Overrides Node's slot 2: runs func_000E6E80 unless flag 1 at 0xa0 is set.
void Object_000E6E80::func_00011C90_1()
{
    if (!(flags_a0 & 1)) {
        func_000E6E80();
    }
}
