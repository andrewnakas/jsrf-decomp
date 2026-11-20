struct Node {
    char unknown_00[0x28];
    Node *child;

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

struct Object_00137910 {
    int func_00137920();
};

struct Object_0011A020 {
    virtual ~Object_0011A020();
    virtual void func_0011A030();
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Slot 1 of the table at 0x1D7BA0: unless func_00137920 of object 0x1deb gives 2, runs func_00011BE0 and
// func_00011C20 on the node.
void Object_0011A020::func_0011A030()
{
    if (((Object_00137910 *)data_0022FCE0->func_000128C0(0x1deb))->func_00137920() != 2) {
        Node *node = (Node *)this;
        if (node) {
            node->func_00011BE0(node);
            node->func_00011C20(node->child);
        }
    }
}
