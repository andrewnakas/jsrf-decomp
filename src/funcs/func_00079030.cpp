int func_00119540(int group, int index, void *position);

struct Node {
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
    virtual ~Node();

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
    char unknown_34[0x10];
};

// The menu node (table 0x1CCD18, destructor 0x780F0).
struct Object_000780F0 : Node {
    char unknown_044[0xe8];
    unsigned int state;
    char unknown_130[0x328];
    int busy;

    void func_00077E40(int first, int second, int show);
    void func_00078210(int first, int second);
    void func_00079030();
};

// Not referenced. By the word at +0x458: 0 runs func_00078210(0, 0), sets bit 30 of +0x12c and takes the node out;
// 3 hides the child (func_00077E40(0, 0, 0)) and 1 runs func_00078210(1, 0), both then clearing the word and running
// func_00078210(0, 1). Every case plays sound 8 / 2.
void Object_000780F0::func_00079030()
{
    switch (busy) {
    case 0:
        func_00078210(0, 0);
        state |= 0x40000000;
        func_00011BE0(this);
        func_00011C20(child);
        break;
    case 3:
        func_00077E40(0, 0, 0);
        busy = 0;
        func_00078210(0, 1);
        break;
    case 1:
        func_00078210(1, 0);
        busy = 0;
        func_00078210(0, 1);
        break;
    }
    func_00119540(8, 2, 0);
}
