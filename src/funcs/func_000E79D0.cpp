struct Node {
    virtual ~Node();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(int argument);

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

struct Object_000E79D0 : Node {
    char unknown_040[0x50];
    unsigned int flags_90;

    void func_000E79D0();
};

// Marks the node and everything below it as dead, then sets flag 0x20 at 0x90.
void Object_000E79D0::func_000E79D0()
{
    if (this) {
        func_00011BE0(this);
        func_00011C20(child);
    }
    flags_90 |= 0x20;
}
