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

struct Owner_000DC160 : Node {
    char unknown_040[0x64];
    unsigned int flags_a4;
};

struct Object_000DC160 {
    int unknown_00;
    Owner_000DC160 *owner;

    void func_000DC160();
};

// Marks the owner at 4, and everything below it, as dead, then sets the flags 0x2020 at its 0xa4.
void Object_000DC160::func_000DC160()
{
    Owner_000DC160 *node = owner;
    if (node) {
        node->func_00011BE0(node);
        node->func_00011C20(node->child);
    }
    owner->flags_a4 |= 0x2020;
}
