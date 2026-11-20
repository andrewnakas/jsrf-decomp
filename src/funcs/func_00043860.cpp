/* sym: ??1Object_00043860@@UAE@XZ = 0x00043860 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
struct Object_00016200 {
    void func_00019760(void *pointer);
};

extern Object_00016200 data_0022FCE8;

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

// The node class whose table is at 0x1CA6C8.
struct Object_00043860 : Node {
    virtual ~Object_00043860();

    char unknown_44[0x38];
    void *block;
};

// Releases the block at +0x7c (func_00019760 of 0x22FCE8).
Object_00043860::~Object_00043860()
{
    data_0022FCE8.func_00019760(block);
}
