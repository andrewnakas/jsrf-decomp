struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000C1270 {
    int func_000C1160(int kind, int count, Vector3 *position);
};

extern Object_000C1270 *data_00257CE4;

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

void func_000C70A0(Node *owner, Vector3 *position, int kind);
void __fastcall func_0014C730(Vector3 *target, Vector3 *direction, float scale);

// The child of Node whose table is at 0x1CEDA0; its handlers (table at 0x218E4C) run by the state at 0x9c.
struct Object_000E6E80 : Node {
    void func_000E6CC0();
    void func_000E6D50();
    void func_000E6D90();
    void func_000E7260();
    void func_000E7620();

    Vector3 origin;
    Vector3 position;
    char unknown_05c[0xc];
    Vector3 previous;
    Vector3 velocity;
    float speed;
    char unknown_084[0x18];
    int state;
    unsigned int flags_a0;
    int count;
    char unknown_0a8[0x488];
    float fade;
};

// Entry 4 of the handlers at 0x218E4C: the value at 0x530 falls by 1/59 down to 0; after 60 calls, state 5 and the
// node unlinks itself and its children.
void Object_000E6E80::func_000E6D90()
{
    if ((fade -= 0.016949153f) < 0.0f) {
        fade = 0.0f;
    }
    if (++count > 60) {
        state = 5;
        func_00011BE0(this);
        func_00011C20(child);
    }
}
