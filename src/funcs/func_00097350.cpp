/* sym: ?func_00011C90_2@Object_00097350@@UAEXXZ = 0x00097350 */
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

struct Owner_00097350 {
    char unknown_000[0xe50];
    int state;
};

// The child of Node whose table is at 0x1CD420.
struct Object_00097350 : Node {
    virtual void func_00011C90_2();
};

// Overrides Node's slot 4: runs slot 1 when the parent's state at 0xe50 is 27.
void Object_00097350::func_00011C90_2()
{
    if (((Owner_00097350 *)func_00011BD0())->state == 27) {
        func_00011C90();
    }
}
