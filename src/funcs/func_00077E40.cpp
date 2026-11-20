/* sym: ??0Object_00114FD0@@QAE@PAUNode@@HIHH@Z = 0x00115510 */
/* const: 0x10003 */
struct Node {
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
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

struct Game {
    void *func_000128C0(int id);
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

// Lane 3's node made at 0x115510 (0x100 bytes).
struct Object_00114FD0 : Node {
    Object_00114FD0(Node *owner, int id, unsigned int flags, int first, int second);

    char unknown_44[0xbc];
};

// The menu object (table 0x1CCD18).
struct Object_000780F0 : Node {
    char unknown_044[0x8c];
    int child_d0;

    void func_00077E40(int first, int second, int show);
};

// Takes out the node whose id is at +0xd0 when it exists; with `show`, makes a new Object_00114FD0 under this object
// with a free id in 0x1208-0x1288 (flags 0x10003) and the two values, else clears the id.
void Object_000780F0::func_00077E40(int first, int second, int show)
{
    if (show) {
        if (child_d0 && data_0022FCE0->func_000128C0(child_d0)) {
            Node *node = (Node *)data_0022FCE0->func_000128C0(child_d0);
            if (node) {
                node->func_00011BE0(node);
                node->func_00011C20(node->child);
            }
        }
        child_d0 = data_0022FCE0->func_000128E0(0x1208, 0x1288);
        new Object_00114FD0(this, child_d0, 0x10003, first, second);
    } else {
        if (data_0022FCE0->func_000128C0(child_d0)) {
            Node *node = (Node *)data_0022FCE0->func_000128C0(child_d0);
            if (node) {
                node->func_00011BE0(node);
                node->func_00011C20(node->child);
            }
        }
        child_d0 = 0;
    }
}
