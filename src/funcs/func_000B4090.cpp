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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};


struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The child of Node whose table is at 0x1CD6E8 (destructor func_000ACFB0): the ids of up to ten children at 0x8c and
// their count at 0xbc.
struct Object_000ACFB0 {
    char unknown_00[0x8c];
    int ids[10];
    char unknown_b4[8];
    int count;

    void func_000B4090(int id);
};

// Called by slot 1: when the id is one of its ten at 0x8c, unlinks that object (func_00011BE0, func_00011C20), clears
// the id and counts it off at 0xbc.
void Object_000ACFB0::func_000B4090(int id)
{
    for (int i = 0; i < 10; i++) {
        if (ids[i] == id) {
            Node *node = (Node *)data_0022FCE0->func_000128C0(id);
            if (node) {
                node->func_00011BE0(node);
                node->func_00011C20(node->child);
                ids[i] = 0;
                count--;
            }
            return;
        }
    }
}
