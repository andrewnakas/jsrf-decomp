/* sym: ??1Object_000C6BF0@@UAE@XZ = 0x000C6B90 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000C6BF0@@UAEXXZ = 0x000C6BF0 */
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


struct Mesh_00017F60;

struct Item_000162A0 {
    int unknown_00[2];
    Mesh_00017F60 *mesh;
    char unknown_0c[8];
    int unknown_14;
};

struct Object_00016200 {
    void func_00019760(void *pointer);
};

extern Object_00016200 data_0022FCE8;

// The base whose slot 1 is shared by the tables at 0x1CE078, 0x1CE0B8, 0x1CE0F8, 0x1CE138 and 0x1CE178 (the
// objects func_000C70A0 creates; func_000C6C40 sets the life at 0x48 to 120).
struct Object_000C6BF0 : Node {
    virtual ~Object_000C6BF0();
    virtual void func_00011C90();

    char unknown_40[8];
    int life;
    Item_000162A0 item;
};

// Hands the mesh of the item at 0x4c, when there is one, to func_00019760 of data_0022FCE8.
Object_000C6BF0::~Object_000C6BF0()
{
    if (item.mesh) {
        data_0022FCE8.func_00019760(item.mesh);
    }
}
