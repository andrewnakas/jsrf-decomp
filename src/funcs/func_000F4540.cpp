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

// The child of Node whose table is at 0x1CF098 (destructor func_000F3F70): its slot 1 (func_000F4480) runs entry
// `state` of the member-function table at 0x21b2dc on itself (func_000F4140 is entry 4).
struct Object_000F44E0 : Node {
    char unknown_040[4];
    int state;
    char unknown_048[0x28];
    int count;

    void func_000F4280();
    void func_000F4540();
};

// Entry 2 of that table: func_000F4280, then counts up at 0x70; past 600, state 3 at 0x44.
void Object_000F44E0::func_000F4540()
{
    func_000F4280();
    if (++count > 600) {
        state = 3;
    }
}
