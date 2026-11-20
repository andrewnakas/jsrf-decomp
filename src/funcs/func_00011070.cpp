struct Node {
    virtual void slot0();
    virtual void slot1();

    unsigned int flags;
    char unknown_08[0x20];
    Node *child;
    Node *previous;
    Node *next;

    void func_00011070();
};

void func_001BA8A0();

void Node::func_00011070()
{
    for (Node *node = this; node; node = node->next) {
        if (!(node->flags & 0x80000000)) {
            func_001BA8A0();
            node->slot1();
            if (node->child) {
                node->child->func_00011070();
            }
        }
    }
}
