/* sym: ?func_00011C90@Object_000DB0F0@@UAEXXZ = 0x000DB330 */
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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);

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

// The class whose table is at 0x1CE6F8 (destructor func_000DAD60).
struct Object_000DB0F0 : Node {
    virtual void func_00011C90();

    void func_000DAE30();
    void func_000DAED0();
    void func_000DAF90();

    int state;
    unsigned int flags;
    int timer;
};

// Slot 1: state 0 runs func_000DAE30 and moves to 1 after 60 calls; in states 1 and 3, with flag 1 at 0x48, the node
// unlinks itself and its children (state 1 becomes 2); then func_000DAED0 and func_000DAF90, except in state 2.
void Object_000DB0F0::func_00011C90()
{
    switch (state) {
    case 0:
        func_000DAE30();
        if (++timer > 60) {
            state = 1;
        }
        break;
    case 1:
        if (flags & 1) {
            state = 2;
            func_00011BE0(this);
            func_00011C20(child);
        }
        break;
    case 2:
        return;
    case 3:
        if (flags & 1) {
            func_00011BE0(this);
            func_00011C20(child);
        }
        break;
    }
    func_000DAED0();
    func_000DAF90();
}
