struct Node {
    char unknown_00[0x28];
    Node *child;

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

struct Object_00113700 {
    virtual ~Object_00113700();
    virtual void func_00113CD0();
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Slot 1 of the tables at 0x1D2AE8 and 0x1D2BB0: unless object 0x1167 exists, runs func_00011BE0 and
// func_00011C20 on the node.
void Object_00113700::func_00113CD0()
{
    if (!data_0022FCE0->func_000128C0(0x1167)) {
        Node *node = (Node *)this;
        if (node) {
            node->func_00011BE0(node);
            node->func_00011C20(node->child);
        }
    }
}
