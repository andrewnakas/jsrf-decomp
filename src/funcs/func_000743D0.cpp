/* sym: ??1Object_00074260@@UAE@XZ = 0x000743D0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

void func_00118870(int value);

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

// The node class whose table is at 0x1CCC58 (slot 1 0x74680).
struct Object_00074260 : Node {
    virtual ~Object_00074260();

    void func_00074260();
};

// Takes out node 0x1164 with everything below it, runs func_00074260 and passes 0 to func_00118870.
Object_00074260::~Object_00074260()
{
    Node *node = (Node *)data_0022FCE0->func_000128C0(0x1164);
    if (node) {
        node->func_00011BE0(node);
        node->func_00011C20(node->child);
    }
    func_00074260();
    func_00118870(0);
}
