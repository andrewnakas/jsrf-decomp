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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The object func_000BAD80 finds by id: up to ten child ids at 0x8c, counted at 0xbc.
struct Object_000B40F0 {
    char unknown_00[0x8c];
    int ids[10];
    char unknown_b4[8];
    int count;

    int id(unsigned int index)
    {
        return index < 10 ? ids[index] : 0;
    }
    void func_000B40F0();
};

// Takes each child whose id is at 0x8c (ten slots) out of the draw links with its children, clears its slot and
// counts it out of 0xbc. The bounds check of the slot index stays inside the loop, as an inline accessor gives it.
void Object_000B40F0::func_000B40F0()
{
    for (int i = 0; i < 10; i++) {
        if (id(i)) {
            Node *node = (Node *)data_0022FCE0->func_000128C0(ids[i]);
            if (node) {
                node->func_00011BE0(node);
                node->func_00011C20(node->child);
                ids[i] = 0;
                count--;
            }
        }
    }
}
