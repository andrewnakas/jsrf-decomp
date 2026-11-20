/* sym: ?func_00011C80@Object_00071040@@UAEXH@Z = 0x00071100 */
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

// The class whose table is at 0x1CCA80 (constructor 0x70E30, destructor 0x71040): overrides slots 1 (71CB0) and 3.
struct Object_00071040 : Node {
    virtual void func_00011C80(int argument);

    char unknown_044[0x54];
    int state;
    char unknown_09c[0x42c];
    int unknown_4c8;

    void func_0006FE40(float scale);
    void func_00070060(float scale);
};

// Slot 3: while the word at +0x4c8 is set, runs func_00070060 (1.1) in state 3 or func_0006FE40 (1) in state 10.
void Object_00071040::func_00011C80(int argument)
{
    if (unknown_4c8) {
        switch (state) {
        case 3:
            func_00070060(1.1f);
            break;
        case 10:
            func_0006FE40(1.0f);
            break;
        }
    }
}
