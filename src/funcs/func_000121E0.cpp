/* sym: ??0Object_000121E0@@QAE@PAUNode@@HI@Z = 0x000121E0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
extern "C" void *memset(void *destination, int value, unsigned int size);

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

// Two words that start out zero.
struct Pair_000121E0 {
    int first;
    int second;
};

// The class whose table is at 0x1C4418 (no virtual functions of its own): two words at +0x44.
struct Object_000121E0 : Node {
    Object_000121E0(Node *owner, int id, unsigned int flags);

    Pair_000121E0 unknown_44;
};

// Only clears the two words at +0x44 (the base of the player).
Object_000121E0::Object_000121E0(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
{
    memset(&unknown_44, 0, sizeof unknown_44);
}
