/* sym: ??1Object_000A1C50@@UAE@XZ = 0x0007E830 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000A1C50@@UAEXXZ = 0x00080340 */
/* sym: ?func_00011C90_1@Object_000A1C50@@UAEXXZ = 0x00080BD0 */
/* sym: ?func_00011C80@Object_000A1C50@@UAEXH@Z = 0x00082770 */
/* sym: ?func_00011C90_3@Object_000A1C50@@UAEXXZ = 0x0007EA00 */
/* sym: ?func_00011C80_1@Object_000A1C50@@UAEXH@Z = 0x00082790 */
/* sym: ?func_00011C80_3@Object_000A1C50@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000A1C50@@UAEXH@Z = 0x000B3DE0 */
struct Node {
    Node(Node *owner, int id, unsigned int flags);
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
    char unknown_34[0x10];
};

// The class whose table is at 0x1C4418 (constructor 0x121E0): no virtual functions of its own, two words at +0x44.
struct Object_000121E0 : Node {
    Object_000121E0(Node *owner, int id, unsigned int flags);

    int unknown_44[2];
};

struct Item_0001DEF0;
struct Item_000657A0;
struct Item_00066A70;
struct Item_0001DCF0;
struct Item_00066D40;
struct Item_00039A10;
struct Entry_00014F90;

// The list objects (one class for the globals that share functions).
struct Object_0001DEF0 {
    void func_0001DEF0(Item_0001DEF0 *item);
};

struct Object_00065730 {
    void func_000657A0(Item_000657A0 *item);
    void func_00066D40(Item_00066D40 *item);
};

struct Object_00039A10 {
    void func_0001DD20(Item_0001DCF0 *item);
    void func_00039A40(Item_00039A10 *item);
    void func_00066A70(Item_00066A70 *item);
};

struct Object_00015130 {
    void func_00014FD0(Entry_00014F90 *entry);
};

struct Object_0006DB80 {
    void func_0006DF30(int key);
};

struct Object_00016200 {
    void func_00019760(void *data);
};

struct Object_0003E750 {
    void func_0003F280(int index);
};

struct Game {
    void func_000127C0(int index, int value);
};

extern Object_0001DEF0 data_0020CC58;
extern Object_0001DEF0 data_001EBABC;
extern Object_0001DEF0 data_001EC050;
extern Object_00065730 data_001FB804;
extern Object_00065730 data_001FB8E8;
extern Object_00039A10 data_001EBAA8;
extern Object_00039A10 data_001EFC74;
extern Object_00039A10 data_001FB820;
extern Object_00039A10 data_001FB8CC;
extern Object_00015130 data_001EB994;
extern Object_0006DB80 data_00251F78;
extern Object_00016200 data_0022FCE8;
extern Object_0003E750 data_002314B0;
extern Game *data_0022FCE0;

// The class whose table is at 0x1CCFF8: overrides slots 1 (80340), 2 (80BD0), 3 (82770), 5 (7EA00), 6 (82790), 12 (B3DE0), 15 (B3DE0).
struct Object_000A1C50 : Object_000121E0 {
    virtual ~Object_000A1C50();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_04c[0x1fc];
    void *unknown_248;
    char unknown_24c[0x24];
    void *unknown_270;
    char unknown_274[0x5c];
    Item_0001DEF0 *item_2d0;
    Item_000657A0 *item_2d4;
    Item_00066A70 *item_2d8;
    char unknown_2dc[0x44];
    Item_00039A10 *item_320;
    int key_324;
    char unknown_328[0x6c];
    Item_0001DCF0 *item_394;
    char unknown_398[0x2c];
    Item_00039A10 *item_3c4;
    Item_0001DEF0 *item_3c8;
    char unknown_3cc[0x54];
    Entry_00014F90 *entry_420;
    char unknown_424[0x48];
    char *buffer_46c;
    char unknown_470[0x828];
    int unknown_c98;
    int unknown_c9c;
    char unknown_ca0[0x260];
    Item_0001DEF0 *item_f00;
    char unknown_f04[0x58];
    Node *children[10];
    char unknown_f84[0x14];
    int unknown_f98;
    char unknown_f9c[4];
    int unknown_fa0;
    char unknown_fa4[0x18];
    int unknown_fbc;
    char unknown_fc0[0x5c];
    Item_00066D40 *item_101c;
    char unknown_1020[0x20];
    int unknown_1040;

    void func_0009CF70();
    void func_000A1D30();
    void func_000A87A0();
};

// The player's destructor: runs func_000A1D30 and func_0009CF70, gives its items back to the eleven lists and the
// table at 0x251F78, runs func_000A87A0, releases its two blocks at 0x22FCE8, deletes its ten children and its buffer,
// releases its slot at 0x2314B0 and, unless +0xc9c is set or +0xc98 is -1, stores settings 0x172 and 0x151 + its
// index.
Object_000A1C50::~Object_000A1C50()
{
    func_000A1D30();
    func_0009CF70();
    data_0020CC58.func_0001DEF0(item_2d0);
    data_001EBABC.func_0001DEF0(item_f00);
    data_001FB804.func_000657A0(item_2d4);
    data_001FB8CC.func_00066A70(item_2d8);
    data_001EBAA8.func_0001DD20(item_394);
    data_001FB8E8.func_00066D40(item_101c);
    data_001EFC74.func_00039A40(item_3c4);
    data_001EC050.func_0001DEF0(item_3c8);
    data_001EB994.func_00014FD0(entry_420);
    data_001FB820.func_00039A40(item_320);
    data_00251F78.func_0006DF30(key_324);
    func_000A87A0();
    if (unknown_248) {
        data_0022FCE8.func_00019760(unknown_248);
    }
    if (unknown_270) {
        data_0022FCE8.func_00019760(unknown_270);
    }
    for (int i = 0; i < 10; i++) {
        if (children[i]) {
            delete children[i];
        }
    }
    if (buffer_46c) {
        delete buffer_46c;
    }
    data_002314B0.func_0003F280(unknown_1040);
    if (!unknown_c9c && unknown_c98 != -1) {
        data_0022FCE0->func_000127C0(0x172, unknown_fa0);
        data_0022FCE0->func_000127C0(unknown_fbc + 0x151, unknown_f98);
    }
}
