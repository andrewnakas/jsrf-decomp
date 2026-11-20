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

struct Owner_000967B0 {
    char unknown_000[0xe50];
    int state;
};

struct Object_000967B0 : Node {
    virtual void func_000967B0(int argument);
};

// Virtual (slot 6 of four vtables, data_001CD320 to data_001CD3E0). Passes the argument to the third virtual
// function when the parent's state at 0xe50 is 27.
void Object_000967B0::func_000967B0(int argument)
{
    if (((Owner_000967B0 *)func_00011BD0())->state == 27) {
        slot3(argument);
    }
}
