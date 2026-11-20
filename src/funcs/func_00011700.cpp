struct Node {
    virtual ~Node();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(int argument);
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(int argument);
    virtual void slot7();
    virtual void slot8();
    virtual void slot9(int argument);
    virtual void slot10();
    virtual void slot11();
    virtual void slot12(int argument);
    virtual void slot13();
    virtual void slot14();
    virtual void slot15(int argument);

    unsigned int flags;
    char unknown_08[0x20];
    Node *child;
    Node *previous;
    Node *next;

    void func_00011700();
};

void func_001BA8A0();

// Calls slot 10 on every node of the tree that is not dead (flag 0x80000000), and on the children of each.
void Node::func_00011700()
{
    for (Node *node = this; node; node = node->next) {
        if (!(node->flags & 0x80000000)) {
            func_001BA8A0();
            node->slot10();
            if (node->child) {
                node->child->func_00011700();
            }
        }
    }
}
