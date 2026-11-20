/* sym: ?func_00011C90_7@Object_0001E140@@UAEXXZ = 0x0001E3C0 */
struct Node {
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
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

// A node with no virtual functions of its own (table 0x1C43D8 repeats Node's slots 1 to 15) and mask 7.
struct Object_00012170 : Node {
    char unknown_44[0x54];
};

// The node class whose table is at 0x1C45C8 (destructor 0x1E140): overrides slots 10 (42880), 11 (1E3C0) and 12
// (1E1A0).
struct Object_0001E140 : Object_00012170 {
    virtual ~Object_0001E140();
    virtual void func_00011C90_7();

    char unknown_098[0x30];
    float value;
    float speed;
    int state;
    unsigned int timer;

    void func_00042890();
};

// Slot 11 (also of the table at 0x1CA5F0): in state 0 adds +0xcc to +0xc8 (kept at most 1) and when the timer at +0xd4
// runs out goes to state 1 with a timer of 30; in state 1 takes itself out (with everything below it) when the timer
// runs out. Then func_00042890.
void Object_0001E140::func_00011C90_7()
{
    switch (state) {
    case 0:
        value += speed;
        if (value > 1.0f)
            value = 1.0f;
        if (timer > 0 && --timer == 0) {
            state = 1;
            timer = 30;
        }
        break;
    case 1:
        if (timer > 0 && --timer == 0) {
            func_00011BE0(this);
            func_00011C20(child);
        }
        break;
    }
    func_00042890();
}
