/* sym: ?func_00011C90_3@Object_00096F60@@UAEXXZ = 0x00096F60 */
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

    Node *func_00011BD0();
};

struct Owner_00096F60 {
    char unknown_000[0xe50];
    int state;
};

// One of six direct children of Node (tables 0x1CD290, 0x1CD2E0, 0x1CD320, 0x1CD360, 0x1CD3A0 and 0x1CD3E0)
// whose slot 5 is this same code.
struct Object_00096F60 : Node {
    virtual void func_00011C90_3();
};

// Overrides Node's slot 5: runs slot 2 when the parent's state at 0xe50 is 27.
void Object_00096F60::func_00011C90_3()
{
    if (((Owner_00096F60 *)func_00011BD0())->state == 27) {
        func_00011C90_1();
    }
}
