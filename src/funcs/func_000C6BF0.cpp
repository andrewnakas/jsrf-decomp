/* sym: ?func_00011C90@Object_000C6BF0@@UAEXXZ = 0x000C6BF0 */
struct Node {
    virtual ~Node();
    virtual void func_00011C90();

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
    char unknown_34[0x10];

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

struct Item_000162A0 {
    char unknown_00[0xc];
    Item_000162A0 *head;
    Item_000162A0 **tail;
    int unknown_14;
    int unknown_18;
    int unknown_1c;
    Item_000162A0 *next;
};

struct Object_00016200 {
    void func_000162A0(Item_000162A0 *item);
};

extern Object_00016200 data_0022FCE8;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0xe20];
    int value_e20;
};

// The base whose slot 1 is shared by the tables at 0x1CE078, 0x1CE0B8, 0x1CE0F8, 0x1CE138 and 0x1CE178 (the
// objects func_000C70A0 creates; func_000C6C40 sets the life at 0x48 to 120).
struct Object_000C6BF0 : Node {
    virtual void func_00011C90();

    char unknown_44[4];
    int life;
    Item_000162A0 item;
};

// Slot 1: once the life at 0x48 runs out, marks itself and everything below it as dead; while the player exists
// with its field at 0xe20 clear, hands the item at 0x4c to data_0022FCE8 (func_000162A0).
void Object_000C6BF0::func_00011C90()
{
    if (--life <= 0) {
        func_00011BE0(this);
        func_00011C20(child);
    }
    Object_000A1C50 *player = (Object_000A1C50 *)data_0022FCE0->func_000128C0(0x2c);
    if (player && player->value_e20 == 0) {
        data_0022FCE8.func_000162A0(&item);
    }
}
