/* sym: ??0Object_000BAC20@@QAE@PAUNode@@HIH@Z = 0x000BB1A0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ??1Object_000BAC20@@UAE@XZ = 0x000BAC20 */
struct Object_00066980 {
    int value;

    void func_00066980(int newValue);
};

extern Object_00066980 data_00257C80;

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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};

// The child of Node whose table is at 0x1CD9E0: it overrides none of Node's slots.
struct Object_000BAC20 : Node {
    Object_000BAC20(Node *owner, int id, unsigned int flags, int shown);
    virtual ~Object_000BAC20();

    char unknown_40[4];
    int values[20];
    int value_94;
    char unknown_98[8];
    int value_a0;
    int value_a4;
    int value_a8;
    int value_ac;
};

void func_00011C90_1(Object_000BAC20 *object);

// Clears its fields, seeds the random generator at data_00257C80 with 0x416c, and passes itself to the empty
// function at 0x11c90 when the last argument is 0.
Object_000BAC20::Object_000BAC20(Node *owner, int id, unsigned int flags, int shown) : Node(owner, id, flags)
{
    for (int i = 0; i < 20; i++) {
        values[i] = 0;
    }
    value_94 = 0;
    value_a4 = 1;
    data_00257C80.func_00066980(0x416c);
    if (!shown) {
        ::func_00011C90_1(this);
    }
    value_a0 = 0;
    value_a8 = 0;
    value_ac = 0;
}
