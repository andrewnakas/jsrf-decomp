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


    void func_00011B90(Node *node);
};

// Deletes a sibling list and everything below it.
void Node::func_00011B90(Node *node)
{
    while (node) {
        Node *next = node->next;
        if (node->child) {
            func_00011B90(node->child);
        }
        delete node;
        node = next;
    }
}
