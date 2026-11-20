/* sym: ?func_00011C90_1@Object_0003BB10@@UAEXXZ = 0x0003BC80 */
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

// One of the entries at +0x50 (0x5c bytes).
struct Entry_0003BC80 {
    char unknown_00[0x1c];
    float time;
    int unknown_20;
    char unknown_24[0x38];
};

// The class whose table is at 0x1CA3E8 (constructor 0x3B940, destructor 0x3BB10): overrides slot 2.
struct Object_0003BB10 : Node {
    virtual void func_00011C90_1();

    char unknown_044[4];
    unsigned int count;
    char unknown_04c[4];
    Entry_0003BC80 *entries;
    char unknown_054[4];
    Motion_0005F060 *motion;
};

// Slot 2: clears +0x20 of each of the +0x48 entries at +0x50 and steps its time (+0x1c) by a half through the motion at
// +0x58 (func_0005E030).
void Object_0003BB10::func_00011C90_1()
{
    for (unsigned int i = 0; i < count; i++) {
        entries[i].unknown_20 = 0;
        func_0005E030(motion, &entries[i].time, 0.5f, 0);
    }
}
