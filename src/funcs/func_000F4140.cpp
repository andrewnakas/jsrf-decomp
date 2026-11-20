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

struct Object_000F44E0 : Node {
    char unknown_040[0x30];
    int count;

    void func_000F4140();
};

// Entry 4 of the member-function table at 0x21b2dc of Object_000F44E0 (table 0x1CF098): counts up at 0x70; past 5
// the node and everything below it are marked dead.
void Object_000F44E0::func_000F4140()
{
    if (++count > 5) {
        func_00011BE0(this);
        func_00011C20(child);
    }
}
