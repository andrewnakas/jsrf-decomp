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

struct Owner_0009B430 {
    char unknown_000[0x8b8];
    int index;
};

extern int data_0020E6D0[];

struct Game {
    int func_000127E0(int index);
    void func_000127C0(int index, int value);
};

extern Game *data_0022FCE0;

struct Object_000A1C50 : Node {
    char unknown_040[0xdc];
    int value_11c;

    void func_0008A530();
    void func_0007FD20();
    void func_000A2130(int value);
    void func_0009B430();
};

// Player handler (the entry at 0x20D89C of its member-function tables): the field at 0x11c from data_0020E6D0 by the
// parent's index at 0x8b8, func_0008A530 and func_0007FD20; then, when game value 0x196 is set, passes it to
// func_000A2130 and clears it to -1.
void Object_000A1C50::func_0009B430()
{
    value_11c = data_0020E6D0[((Owner_0009B430 *)func_00011BD0())->index];
    func_0008A530();
    func_0007FD20();
    int value = data_0022FCE0->func_000127E0(0x196);
    if (value != -1) {
        func_000A2130(value);
        data_0022FCE0->func_000127C0(0x196, -1);
    }
}
