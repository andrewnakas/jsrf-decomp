/* sym: ??1Object_0004FBC0@@UAE@XZ = 0x0004FBC0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
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

// The node class whose table is at 0x1CAB98.
struct Object_0004FBC0 : Node {
    virtual ~Object_0004FBC0();

    char unknown_44[0x848];
    char *first;
    char unknown_890[4];
    char *blocks[3];
};

// Frees the blocks at +0x88c, +0x894, +0x898 and +0x89c.
Object_0004FBC0::~Object_0004FBC0()
{
    delete first;
    delete blocks[0];
    delete blocks[1];
    delete blocks[2];
}
