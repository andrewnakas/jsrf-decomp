/* sym: ?func_00011C80_1@Object_000AE660@@UAEXH@Z = 0x000AE660 */
struct Game {
    void *func_000128C0(int id);
};

struct Target_000AE660 {
    char unknown_00[0xa4];
    int value_a4;
};

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

// One of 17 direct children of Node (tables 0x1CD608 to 0x1CDBA0, among them 0x1CD658 and 0x1CD6A0) whose
// slot 6 is this same code.
struct Object_000AE660 : Node {
    virtual void func_00011C80_1(int argument);
};

extern Game *data_0022FCE0;

// Overrides Node's slot 6: passes the argument to slot 3 unless object 0xeb exists with its field at 0xa4
// clear.
void Object_000AE660::func_00011C80_1(int argument)
{
    Target_000AE660 *target = (Target_000AE660 *)data_0022FCE0->func_000128C0(0xeb);
    if (!target || target->value_a4) {
        func_00011C80(argument);
    }
}
