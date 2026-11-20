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

struct Owner_0009B290 {
    char unknown_000[0x8b4];
    int value_8b4;
};

struct Object_000A1C50 : Node {
    char unknown_040[0xdc];
    int value_11c;

    void func_0009B290();
};

// Sets the field at 0x11c to 3 and clears the field at 0x8b4 of the parent.
void Object_000A1C50::func_0009B290()
{
    value_11c = 3;
    ((Owner_0009B290 *)func_00011BD0())->value_8b4 = 0;
}
