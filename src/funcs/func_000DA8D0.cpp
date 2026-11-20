/* sym: ?func_00011C90@Object_000DA3E0@@UAEXXZ = 0x000DA8D0 */
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

// The class whose table is at 0x1CE658 (destructor func_000DA360).
struct Object_000DA3E0 : Node {
    virtual void func_00011C90();

    void func_000DA710();

    int state;
    char unknown_48[4];
    int timer;
};

// Slot 1: state 0 waits 120 calls and moves to 1 (timer restarted), state 1 waits on to 120 and moves to 3, and in
// state 3 the node unlinks itself and its children; then func_000DA710.
void Object_000DA3E0::func_00011C90()
{
    switch (state) {
    case 0:
        if (++timer >= 120) {
            state = 1;
            timer = 0;
        }
        break;
    case 1:
        if (++timer >= 120) {
            state = 3;
        }
        break;
    case 3:
        func_00011BE0(this);
        func_00011C20(child);
        break;
    }
    func_000DA710();
}
