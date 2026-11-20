/* const: 0x40000 */
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


    void func_00011260();
};

void func_001BA9C0();
void func_001BAA50();

// Calls slot 3 with 0 on every node of the tree that has flag 0x40000, each between func_001BA9C0 and func_001BAA50.
void Node::func_00011260()
{
    for (Node *node = this; node; node = node->next) {
        if (node->flags & 0x40000) {
            func_001BA9C0();
            node->slot3(0);
            func_001BAA50();
        }
        if (node->child) {
            node->child->func_00011260();
        }
    }
}
