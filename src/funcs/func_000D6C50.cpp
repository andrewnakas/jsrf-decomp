struct Node {
    virtual ~Node();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(int argument);

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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

struct Object_000D6C50 {
    int unknown_00;
    Node *node;

    void func_000D6C50();
};

// Marks the node at 4, and everything below it, as dead.
void Object_000D6C50::func_000D6C50()
{
    Node *node = this->node;
    if (node) {
        node->func_00011BE0(node);
        node->func_00011C20(node->child);
    }
}
