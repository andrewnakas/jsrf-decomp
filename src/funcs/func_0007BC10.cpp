/* sym: ??0Object_0007BC10@@QAE@PAUNode@@HI@Z = 0x0007BC10 */
/* sym: ??1Object_0007BC10@@UAE@XZ = 0x0007BC90 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
// Seeds the engine's random generator (0x22E58C).
void func_0014C2A0(int seed);

// The 15-bit pseudo-random generator (data_00251F28).
struct Object_00066980 {
    int value;
    void func_00066980(int newValue);
};

extern Object_00066980 data_00251F28;

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

// The node class whose table is at 0x1CCEB8 (destructor 0x7BC90).
struct Object_0007BC10 : Node {
    Object_0007BC10(Node *owner, int id, unsigned int flags);
    virtual ~Object_0007BC10();

    char unknown_44[4];
    int unknown_48;
};

// Seeds both random generators with 0x416c and clears +0x48.
Object_0007BC10::Object_0007BC10(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
{
    func_0014C2A0(0x416c);
    data_00251F28.func_00066980(0x416c);
    unknown_48 = 0;
}
