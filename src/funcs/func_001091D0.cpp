struct Game {
    void *func_000128C0(int id);
};

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

// Object 0x1163.
struct Object_000FEDB0 {
    void func_000FF820();
};

// The objects with ids 0x115e to 0x1162 (table 0x1D2020).
struct Object_00107FE0 : Node {
    char unknown_0040[0x34];
    int childId_74;
    char unknown_0078[0xc];
    int childId_84;
    int childId_88;
    char unknown_008c[0x1620];
    unsigned int mask;
    char unknown_16b0[0x50];
    unsigned int state;

    void func_00108870(unsigned int mask, int set);
    void func_001091D0();
};

extern Game *data_0022FCE0;

// Clears every bit at 0x16ac (func_00108870), has object 0x1163 run func_000FF820, marks the objects whose ids are
// at 0x88, 0x74 and 0x84 as dead (with everything below them) and forgets those ids, and clears bit 29 at 0x1700.
void Object_00107FE0::func_001091D0()
{
    mask = 0;
    func_00108870(0xffffffff, 0);
    Object_000FEDB0 *menu = (Object_000FEDB0 *)data_0022FCE0->func_000128C0(0x1163);
    if (menu) {
        menu->func_000FF820();
    }
    if (childId_88 != -1) {
        if (data_0022FCE0->func_000128C0(childId_88)) {
            Node *node = (Node *)data_0022FCE0->func_000128C0(childId_88);
            if (node) {
                node->func_00011BE0(node);
                node->func_00011C20(node->child);
            }
        }
        childId_88 = -1;
    }
    if (childId_74 != -1) {
        if (data_0022FCE0->func_000128C0(childId_74)) {
            Node *node = (Node *)data_0022FCE0->func_000128C0(childId_74);
            if (node) {
                node->func_00011BE0(node);
                node->func_00011C20(node->child);
            }
        }
        childId_74 = -1;
    }
    if (childId_84 != -1) {
        if (data_0022FCE0->func_000128C0(childId_84)) {
            Node *node = (Node *)data_0022FCE0->func_000128C0(childId_84);
            if (node) {
                node->func_00011BE0(node);
                node->func_00011C20(node->child);
            }
        }
        childId_84 = -1;
    }
    state &= ~0x20000000;
}
