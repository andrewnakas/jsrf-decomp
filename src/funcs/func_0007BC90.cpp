/* sym: ??1Object_0007BC10@@UAE@XZ = 0x0007BC90 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
int func_000256C0(unsigned int index, int argument);
void func_00025740(unsigned int index, int argument);

// The list at 0x1FA05C.
struct Object_0004D8C0 {
    void func_0004DAA0();
};

extern Object_0004D8C0 data_001FA05C;

struct Node {
    virtual ~Node();

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

// The node class whose table is at 0x1CCEB8 (constructor 0x7BC10).
struct Object_0007BC10 : Node {
    virtual ~Object_0007BC10();

    char unknown_44[4];
    int unknown_48;
};

// Empties the list at 0x1FA05C (func_0004DAA0) and stops whatever of 0x17, 0x11, 0xa, 0x16, 0x12 (both 0 and 1),
// 0x13 and 0x15 still runs (func_000256C0 / func_00025740).
Object_0007BC10::~Object_0007BC10()
{
    data_001FA05C.func_0004DAA0();
    if (func_000256C0(0x17, 0)) {
        func_00025740(0x17, 0);
    }
    if (func_000256C0(0x11, 0)) {
        func_00025740(0x11, 0);
    }
    if (func_000256C0(0xa, 0)) {
        func_00025740(0xa, 0);
    }
    if (func_000256C0(0x16, 0)) {
        func_00025740(0x16, 0);
    }
    if (func_000256C0(0x12, 0)) {
        func_00025740(0x12, 0);
    }
    if (func_000256C0(0x12, 1)) {
        func_00025740(0x12, 1);
    }
    if (func_000256C0(0x13, 0)) {
        func_00025740(0x13, 0);
    }
    if (func_000256C0(0x15, 0)) {
        func_00025740(0x15, 0);
    }
}
