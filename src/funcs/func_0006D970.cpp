/* sym: ?func_00011C90_1@Object_0006CEE0@@UAEXXZ = 0x0006D970 */
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

// The class whose table is at 0x1CC5D0 (constructor 0x6D9A0, destructor 0x6CEE0): overrides slots 1 (6D770) and 2.
struct Object_0006CEE0 : Node {
    virtual void func_00011C90_1();

    char unknown_044[0x14];
    int unknown_58;
    char unknown_05c[0x64];
    int unknown_c0;
    int unknown_c4;

    void func_0006D4C0(int argument);
};

// Slot 2: while the word at +0xc4 is not -1, runs func_0006D4C0 with the word at +0xc0, twice when +0x58 is 4.
void Object_0006CEE0::func_00011C90_1()
{
    if (unknown_c4 != -1) {
        if (unknown_58 == 4) {
            func_0006D4C0(unknown_c0);
        }
        func_0006D4C0(unknown_c0);
    }
}
