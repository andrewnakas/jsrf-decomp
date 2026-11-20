/* sym: ?func_00011C80@Object_0003F760@@UAEXH@Z = 0x000402C0 */
struct Object_0006A960 {
    int func_0006AC10(int index);
};

extern Object_0006A960 data_0020C6C0;

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

// The class whose table is at 0x1CA558 (destructor 0x3F760): overrides slots 1 (3FEC0), 3 (402C0), 6 (40300).
struct Object_0003F760 : Node {
    virtual void func_00011C80(int argument);

    char unknown_044[0x144];
    int unknown_188;

    void func_0003EBC0();
    void func_0003F9E0(int pass);
};

// Slot 3: while bit +0x188 of the set at 0x20C6C0 is on, runs func_0003F9E0 for the pass, after func_0003EBC0 for
// pass 0.
void Object_0003F760::func_00011C80(int argument)
{
    if (data_0020C6C0.func_0006AC10(unknown_188)) {
        if (!argument) {
            func_0003EBC0();
        }
        func_0003F9E0(argument);
    }
}
