/* sym: ?func_00011C90_1@Object_000DB0F0@@UAEXXZ = 0x000DB3D0 */
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

// The child of Node whose table is at 0x1CE6F8.
struct Object_000DB0F0 : Node {
    char unknown_40[4];
    int state;

    void func_000DB0F0();
    virtual void func_00011C90_1();
};

// Overrides Node's slot 2: runs func_000DB0F0 unless the state is 2.
void Object_000DB0F0::func_00011C90_1()
{
    if (state != 2) {
        func_000DB0F0();
    }
}
