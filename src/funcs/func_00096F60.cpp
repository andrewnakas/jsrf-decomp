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

    Node *func_00011BD0();
};

struct Owner_00096F60 {
    char unknown_000[0xe50];
    int state;
};

struct Object_00096F60 : Node {
    virtual void func_00096F60();
};

// Virtual (slot 5 of six vtables, data_001CD290 to data_001CD3E0). Runs the second virtual function when the
// parent's state at 0xe50 is 27.
void Object_00096F60::func_00096F60()
{
    if (((Owner_00096F60 *)func_00011BD0())->state == 27) {
        slot2();
    }
}
