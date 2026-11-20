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

struct Owner_00097350 {
    char unknown_000[0xe50];
    int state;
};

struct Object_00097350 : Node {
    virtual void func_00097350();
};

// Virtual (slot 4 of the vtable at data_001CD420). Runs the first virtual function after the destructor when
// the parent's state at 0xe50 is 27.
void Object_00097350::func_00097350()
{
    if (((Owner_00097350 *)func_00011BD0())->state == 27) {
        slot1();
    }
}
