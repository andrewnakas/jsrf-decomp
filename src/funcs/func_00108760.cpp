/* sym: ??0Object_00107FE0@@QAE@PAUNode@@HIH@Z = 0x001074B0 */
struct Game {
    int func_000128E0(int first, int last);
};

struct Node {
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C90_5();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C90_7();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C90_9();
    virtual void func_00011C80_4(int argument);

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
};

// The objects with ids 0x115e to 0x1162 (table 0x1D2020); the constructor keeps the owner's id at 0x16b8.
struct Object_00107FE0 {
    Object_00107FE0(Node *owner, int id, unsigned int flags, int owner_id);

    char unknown_0000[0x1708];
};

extern Game *data_0022FCE0;

// Creates one of the objects 0x115e to 0x1162 under the owner (flags 0, with the owner's id) and returns its id.
int func_00108760(Node *owner)
{
    int id = data_0022FCE0->func_000128E0(0x115e, 0x1162);
    new Object_00107FE0(owner, id, 0, owner->id);
    return id;
}
