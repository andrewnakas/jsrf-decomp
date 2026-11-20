/* sym: ?func_00011C90@Object_000EAD20@@UAEXXZ = 0x000EB200 */
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

// The class whose table is at 0x1CEE90 (destructor func_000EADE0).
struct Object_000EAD20 : Node {
    virtual void func_00011C90();

    void func_000EAFC0();

    char unknown_044[0xc];
    float time;
    float alpha;
};

// Slot 1: the time at 0x50 grows by 1.1574; past 300 the node unlinks itself and its children, past 200 the alpha at
// 0x54 falls from 1 by 0.01 a unit; while the alpha is above 0.5, func_000EAFC0.
void Object_000EAD20::func_00011C90()
{
    float now = time + 1.1574074f;
    time = now;
    if (now > 300.0f) {
        func_00011BE0(this);
        func_00011C20(child);
    } else if (now > 200.0f) {
        alpha = 1.0f - (now - 200.0f) * 0.01f;
    }
    if (alpha > 0.5f) {
        func_000EAFC0();
    }
}
