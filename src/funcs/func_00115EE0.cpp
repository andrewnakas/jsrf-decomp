struct Node {
    char unknown_00[0x28];
    Node *child;

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

struct Object_00115EE0 {
    char unknown_000[0x12c];
    unsigned int flags;
};

struct Object_00115E20 {
    virtual ~Object_00115E20();
    virtual void func_00115EE0();
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Slot 1 of the table at 0x1D3770: unless object 0x1167 exists without bit 30 of its flags, runs func_00011BE0
// and func_00011C20 on the node.
void Object_00115E20::func_00115EE0()
{
    Object_00115EE0 *object = (Object_00115EE0 *)data_0022FCE0->func_000128C0(0x1167);
    Node *node = (Node *)this;
    if (!object) {
        if (node) {
            node->func_00011BE0(node);
            node->func_00011C20(node->child);
        }
    } else if (object->flags & 0x40000000) {
        if (node) {
            node->func_00011BE0(node);
            node->func_00011C20(node->child);
        }
    }
}
