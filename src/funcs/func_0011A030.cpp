/* sym: ?func_00011C90@Object_0011A020@@UAEXXZ = 0x0011A030 */
struct Node {
    Node(Node *owner, int id, unsigned int flags);
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
    char unknown_34[0x60];

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

struct Object_00137910 {
    int func_00137920();
};

struct Object_0011A020 : Node {
    virtual ~Object_0011A020();
    virtual void func_00011C90();
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Override of Node's slot 1 in the class whose table is at 0x1D7BA0 (destructor 0x11A020): unless func_00137920
// of object 0x1deb gives 2, runs func_00011BE0 and func_00011C20 on the node.
void Object_0011A020::func_00011C90()
{
    if (((Object_00137910 *)data_0022FCE0->func_000128C0(0x1deb))->func_00137920() != 2) {
        Node *node = this;
        if (node) {
            node->func_00011BE0(node);
            node->func_00011C20(node->child);
        }
    }
}
