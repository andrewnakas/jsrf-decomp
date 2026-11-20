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
};

struct Game {
    void func_00012840(Node *node);
    void func_00012890(int id);
};

extern Game *data_0022FCE0;

// Marks a node as dead (flag 0x80000000), takes it out of the draw list and unregisters its id.
void Node::func_00011BE0(Node *node)
{
    if (!(node->flags & 0x80000000)) {
        node->flags |= 0x80000000;
        data_0022FCE0->func_00012840(node);
        data_0022FCE0->func_00012890(node->id);
    }
}
