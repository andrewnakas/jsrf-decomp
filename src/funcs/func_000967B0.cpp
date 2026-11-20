/* sym: ?func_00011C80_1@Object_000967B0@@UAEXH@Z = 0x000967B0 */
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

struct Owner_000967B0 {
    char unknown_000[0xe50];
    int state;
};

// One of four direct children of Node (tables 0x1CD320, 0x1CD360, 0x1CD3A0 and 0x1CD3E0) whose slot 6 is this
// same code.
struct Object_000967B0 : Node {
    virtual void func_00011C80_1(int argument);
};

// Overrides Node's slot 6: passes the argument to slot 3 when the parent's state at 0xe50 is 27.
void Object_000967B0::func_00011C80_1(int argument)
{
    if (((Owner_000967B0 *)func_00011BD0())->state == 27) {
        func_00011C80(argument);
    }
}
