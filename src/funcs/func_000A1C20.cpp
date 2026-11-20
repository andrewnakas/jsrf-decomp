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

struct Object_00067030 {
    void func_00067030(int slot, int mode, int value);
};

struct Owner_000A1C20 {
    char unknown_000[0x8ac];
    int index;
};

extern Object_00067030 data_00251F2C;
extern int data_00215770[];

struct Object_000A1C50 : Node {
    void func_000A1C20();
};

// When the parent's index at 0x8ac is set, passes the entry of data_00215770 for it to
// data_00251F2C.func_00067030 with mode 0.
void Object_000A1C50::func_000A1C20()
{
    int index = ((Owner_000A1C20 *)func_00011BD0())->index;
    if (index != -1) {
        data_00251F2C.func_00067030(data_00215770[index], 0, 0);
    }
}
