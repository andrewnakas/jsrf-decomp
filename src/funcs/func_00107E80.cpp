/* const: 0x200100 */
/* sym: ??0Object_00101180@@QAE@PAUNode@@HIHHHH@Z = 0x00100F40 */
struct Game {
    void *func_000128C0(int id);
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

// The child of Node whose table is at 0x1D1D48 (0x1a4 bytes).
struct Object_00101180 : Node {
    Object_00101180(Node *parent, int id, unsigned int mask, int ownerId, int kind, int first, int second);
    virtual ~Object_00101180();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);

    char unknown_040[0x164];
};

// The objects with ids 0x115e to 0x1162 (table 0x1D2020).
struct Object_00107FE0 : Node {
    void func_00107E80(int kind, int first, int second);
};

extern Game *data_0022FCE0;

// Makes an Object_00101180 (mask 0x200100, with this object's id, the kind and both values): kind 0 under this
// object, kind 1 under object 9.
void Object_00107FE0::func_00107E80(int kind, int first, int second)
{
    switch (kind) {
    case 0:
        new Object_00101180(this, -1, 0x200100, id, 0, first, second);
        break;
    case 1:
        new Object_00101180((Node *)data_0022FCE0->func_000128C0(9), -1, 0x200100, id, 1, first, second);
        break;
    }
}
