/* sym: ??1Object_000BB710@@UAE@XZ = 0x000BB710 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000BB710@@UAEXXZ = 0x000BB7B0 */
/* sym: ?func_00011C80@Object_000BB710@@UAEXH@Z = 0x000BBA40 */
/* sym: ?func_00011C90_2@Object_000BB710@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_3@Object_000BB710@@UAEXXZ = 0x000AEE80 */
/* sym: ?func_00011C80_1@Object_000BB710@@UAEXH@Z = 0x000AE660 */
/* sym: ?func_00011C80_3@Object_000BB710@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000BB710@@UAEXH@Z = 0x000B3DE0 */
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
struct Item_00017940;

struct Object_00016200 {
    void func_000178D0(Item_00017940 *item);
};

extern Object_00016200 data_0022FCE8;

struct Object_0003E750 {
    void func_0003F280(int key);
};

extern Object_0003E750 data_002314B0;

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CDA60).
struct Object_000BB710 : Node {
    virtual ~Object_000BB710();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_040[0x68];
    int sound;
    char unknown_0ac[0xc];
    int key;
    char unknown_0bc[0xd8];
    void *buffer;
    char unknown_198[0x14];
    int registered;
    Item_00017940 *item;
};

// Unregisters the item at 0x1b0 (func_000178D0 of data_0022FCE8) when the field at 0x1ac is set, frees the buffer
// at 0x194 when there is one, and passes the key at 0xb8 to func_0003F280 of data_002314B0 when the field at 0xa8
// is set.
Object_000BB710::~Object_000BB710()
{
    if (registered) {
        data_0022FCE8.func_000178D0(item);
    }
    if (buffer) {
        operator delete(buffer);
    }
    if (sound) {
        data_002314B0.func_0003F280(key);
    }
}
