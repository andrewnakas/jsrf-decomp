/* sym: ?func_00011C90_3@Object_000A1C50@@UAEXXZ = 0x0007EA00 */
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

struct Vector3 {
    float x;
    float y;
    float z;
};

// The class whose table is at 0x1C4418 (constructor 0x121E0): no virtual functions of its own, two words at +0x44.
struct Object_000121E0 : Node {
    Object_000121E0(Node *owner, int id, unsigned int flags);

    int unknown_44[2];
};

// The class whose table is at 0x1CCFF8: overrides slots 1 (80340), 2 (80BD0), 3 (82770), 5 (7EA00), 6 (82790), 12 (B3DE0), 15 (B3DE0).
struct Object_000A1C50 : Object_000121E0 {
    virtual ~Object_000A1C50();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_4c[0xd0];
    int unknown_11c;
    char unknown_120[0xb74];
    int unknown_c94;
    char unknown_c98[0xc];
    Vector3 position;
    Vector3 unknown_cb0;
    char unknown_cbc[0x194];
    int unknown_e50;
    char unknown_e54[0x138];
    int unknown_f8c[3];
    char unknown_f98[0x15c];
    int unknown_10f4;
    char unknown_10f8[0x10];
    int unknown_1108[3];

    void func_0009CFF0();
    void func_0009E910();
};

// Slot 5 of the table at 0x1CCFF8: in state 0x1b, takes the value at +0x10f4, runs func_0009E910, keeps the position
// at +0xcb0, takes the three words at +0x1108 that are set, runs func_0009CFF0 and counts the step at +0xc94.
void Object_000A1C50::func_00011C90_3()
{
    if (unknown_e50 == 0x1b) {
        unknown_11c = unknown_10f4;
        func_0009E910();
        unknown_cb0 = position;
        if (unknown_1108[0] != -1) {
            unknown_f8c[0] = unknown_1108[0];
        }
        if (unknown_1108[1] != -1) {
            unknown_f8c[1] = unknown_1108[1];
        }
        if (unknown_1108[2] != -1) {
            unknown_f8c[2] = unknown_1108[2];
        }
        func_0009CFF0();
        unknown_c94++;
    }
}
