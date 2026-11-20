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

struct Object_000DF2E0 : Node {
    char unknown_040[0x1c];
    float timer;

    void func_000DF2E0();
};

// Counts the timer at 0x5c down by 1/30; when it runs out the node and everything below it are marked dead.
void Object_000DF2E0::func_000DF2E0()
{
    timer -= 0.033333335f;
    if (timer <= 0.0f) {
        timer = 0.0f;
        func_00011BE0(this);
        func_00011C20(child);
    }
}
