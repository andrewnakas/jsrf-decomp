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

    void func_00011B90(Node *node);
    void func_00011EE0();
};

void func_001BA8A0();

// Runs slot 11 on every node of the tree. A node that is dead (flag 0x80000000), before or after its turn, is
// deleted with everything below it.
void Node::func_00011EE0()
{
    Node *node = this;
    while (node) {
        Node *next = node->next;
        if (node->flags & 0x80000000) {
            Node *child = node->child;
            while (child) {
                Node *childNext = child->next;
                if (child->child) {
                    func_00011B90(child->child);
                }
                delete child;
                child = childNext;
            }
            delete node;
        } else {
            func_001BA8A0();
            node->slot11();
            if (node->flags & 0x80000000) {
                func_00011B90(node->child);
                delete node;
            } else if (node->child) {
                node->child->func_00011EE0();
            }
        }
        node = next;
    }
}
