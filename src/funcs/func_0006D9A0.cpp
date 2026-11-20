/* sym: ??0Object_0006CEE0@@QAE@PAUNode@@HIHHHH@Z = 0x0006D9A0 */
/* sym: ??1Object_0006CEE0@@UAE@XZ = 0x0006CEE0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
extern "C" void *memset(void *destination, int value, unsigned int size);

int func_00038860(int kind);
void func_00118800();

struct Node {
    Node(Node *owner, int id, unsigned int flags);
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

// The class whose table is at 0x1CC5D0 (constructor 0x6D9A0, destructor 0x6CEE0; 0x188 bytes).
struct Object_0006CEE0 : Node {
    Object_0006CEE0(Node *owner, int id, unsigned int flags, int kind, int first, int second, int third);
    virtual ~Object_0006CEE0();

    int unknown_044;
    int unknown_048;
    int kind;
    int unknown_050;
    int third;
    char unknown_058[0x10];
    int unknown_068;
    char unknown_06c[0xc];
    int unknown_078;
    int unknown_07c;
    char unknown_080[0x44];
    int first;
    char unknown_0c8[0xc0];

    void func_0006D370(int argument);
};

// Clears everything from +0x44 on, keeps the kind (+0x4c, with func_00038860 of it at +0x48) and the arguments
// (+0xc4, +0x54), sets +0x78 and +0x7c to 30, +0x68 to -1 and +0x50 to 1, runs func_0006D370 with `second` when
// `first` is not negative and then func_00118800.
Object_0006CEE0::Object_0006CEE0(Node *owner, int id, unsigned int flags, int kind, int first, int second, int third)
    : Node(owner, id, flags)
{
    memset(&unknown_044, 0, 0x144);
    this->kind = kind;
    unknown_048 = func_00038860(kind);
    unknown_07c = unknown_078 = 30;
    this->third = third;
    unknown_068 = -1;
    unknown_050 = 1;
    this->first = first;
    if (first >= 0) {
        func_0006D370(second);
    }
    func_00118800();
}
