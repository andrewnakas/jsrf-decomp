/* sym: ?func_00011C90_1@Object_00043860@@UAEXXZ = 0x00043910 */
struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float step, int hold);

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

// The class whose table is at 0x1CA6C8 (constructor 0x43710, destructor 0x43860): overrides slot 2.
struct Object_00043860 : Node {
    virtual void func_00011C90_1();

    char unknown_044[0x14];
    Motion_0005F060 *motion;
    float time;
    int unknown_60;
    int unknown_64;
};

// Slot 2: while +0x60 is set, clears +0x64 and steps the motion at +0x58 by a half (func_0005E030); else takes the
// object out.
void Object_00043860::func_00011C90_1()
{
    if (unknown_60) {
        unknown_64 = 0;
        func_0005E030(motion, &time, 0.5f, 0);
    } else {
        func_00011BE0(this);
        func_00011C20(child);
    }
}
