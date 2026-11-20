/* const: 0x40000 */
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

    void func_000116C0();
};

void func_001BA9C0();
void func_001BAA50();

// Calls slot 9 with 0 on every node of the tree that has flag 0x40000, each between func_001BA9C0 and func_001BAA50.
void Node::func_000116C0()
{
    for (Node *node = this; node; node = node->next) {
        if (node->flags & 0x40000) {
            func_001BA9C0();
            node->slot9(0);
            func_001BAA50();
        }
        if (node->child) {
            node->child->func_000116C0();
        }
    }
}
