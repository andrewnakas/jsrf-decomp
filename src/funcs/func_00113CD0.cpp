/* sym: ?func_00011C90@Object_00113700@@UAEXXZ = 0x00113CD0 */
struct Node {
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C90_5();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C90_7();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C90_9();
    virtual void func_00011C80_4(int argument);

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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

struct Object_00113700 : Node {
    virtual ~Object_00113700();
    virtual void func_00011C90();
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Slot 1 of the tables at 0x1D2AE8 and 0x1D2BB0: unless object 0x1167 exists, runs func_00011BE0 and
// func_00011C20 on the node.
void Object_00113700::func_00011C90()
{
    if (!data_0022FCE0->func_000128C0(0x1167)) {
        Node *node = (Node *)this;
        if (node) {
            node->func_00011BE0(node);
            node->func_00011C20(node->child);
        }
    }
}
