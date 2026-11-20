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


    void func_00011B60(Node *first, Node *newParent);
};

// Appends this node to the end of a sibling list and sets its parent.
void Node::func_00011B60(Node *first, Node *newParent)
{
    while (first->next) {
        first = first->next;
    }
    first->next = this;
    previous = first;
    parent = newParent;
}
