/* sym: ??1Object_0001DA20@@UAE@XZ = 0x0001DA20 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
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

// A camera node with the table at 0x1C4580 (constructor 0x1DAF0).
struct Object_0001DA20 : Object_00012170 {
    virtual ~Object_0001DA20();

    int child;
};

// Takes out the node whose id it keeps at +0x98, with everything below it.
Object_0001DA20::~Object_0001DA20()
{
    if (child) {
        Node *node = (Node *)data_0022FCE0->func_000128C0(child);
        if (node) {
            node->func_00011BE0(node);
            node->func_00011C20(node->child);
        }
    }
}
