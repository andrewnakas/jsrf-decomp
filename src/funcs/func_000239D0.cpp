/* sym: ??1Object_000239D0@@UAE@XZ = 0x000239D0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
void func_00118780(int value);

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

// A node with no virtual functions of its own (table 0x1C43D8 repeats Node's slots 1 to 15) and mask 7.
struct Object_00012170 : Node {
    Object_00012170(Node *owner, int id, unsigned int flags);

    char unknown_44[0x50];
    int unknown_94;
};

// The class whose table is at 0x1C4C88: overrides slots 4 (23C50), 5 (23F10) and 6 (23F20).
struct Object_000239D0 : Object_00012170 {
    virtual ~Object_000239D0();
};

// Passes 0 to func_00118780 on the way out.
Object_000239D0::~Object_000239D0()
{
    func_00118780(0);
}
