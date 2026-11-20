/* sym: ?func_00011C80@Object_000A1C50@@UAEXH@Z = 0x00082770 */
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

// The class whose table is at 0x1C4418 (constructor 0x121E0): no virtual functions of its own, two words at +0x44.
struct Object_000121E0 : Node {
    Object_000121E0(Node *owner, int id, unsigned int flags);

    int unknown_44[2];
};

// The class whose table is at 0x1CCFF8: overrides slots 1 (80340), 2 (80BD0), 3 (82770), 5 (7EA00), 6 (82790), 12 (B3DE0), 15 (B3DE0).
struct Object_000A1C50 : Object_000121E0 {
    virtual ~Object_000A1C50();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_4c[0xe04];
    int unknown_e50;

    void func_00081860(int argument);
};

// Slot 3 of the table at 0x1CCFF8: passes its argument to func_00081860 unless the field at +0xe50 is 0x1b.
void Object_000A1C50::func_00011C80(int argument)
{
    if (unknown_e50 != 0x1b) {
        func_00081860(argument);
    }
}
