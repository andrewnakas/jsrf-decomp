/* sym: ?func_00011C90@Object_00060650@@UAEXXZ = 0x00060AC0 */
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

struct Game {
    void *func_000128C0(int index);
};

extern Game *data_0022FCE0;

int func_000256C0(unsigned int index, int argument);

// The class whose table is at 0x1CB000: overrides slots 1 (60AC0), 4 (AECC0), 10 (AECC0).
struct Object_00060650 : Node {
    virtual ~Object_00060650();
    virtual void func_00011C90();
    virtual void func_00011C90_2();
    virtual void func_00011C90_6();

    Object_00060650(Node *owner, int id, unsigned int flags, int unused);

    unsigned int unknown_44;
    int unknown_48;
    int unknown_4c;
};

// Slot 1: takes game resource 9; while +0x4c is set, looks for the first of the six entries of handler 0xe that
// answers (func_000256C0), keeps its number at +0x44 and clears +0x4c.
void Object_00060650::func_00011C90()
{
    data_0022FCE0->func_000128C0(9);
    if (unknown_4c) {
        unsigned int i;
        for (i = 0; i <= 5; i++) {
            if (func_000256C0(0xe, i)) {
                break;
            }
        }
        if (i <= 5) {
            unknown_44 = i;
            unknown_4c = 0;
        }
    }
}
