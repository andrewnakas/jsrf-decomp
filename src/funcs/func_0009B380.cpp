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

struct Owner_0009B380 {
    char unknown_000[0x8b8];
    int index;
};

extern int data_0020E6D0[];

struct Object_000A1C50 : Node {
    char unknown_040[0xdc];
    int value_11c;

    void func_0008A530();
    void func_0009B380();
};

// Takes the field at 0x11c from the table data_0020E6D0, by the parent's index at 0x8b8, then runs
// func_0008A530.
void Object_000A1C50::func_0009B380()
{
    value_11c = data_0020E6D0[((Owner_0009B380 *)func_00011BD0())->index];
    func_0008A530();
}
