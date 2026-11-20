/* sym: ??1Object_000ACFB0@@UAE@XZ = 0x000ACFB0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000ACFB0@@UAEXXZ = 0x000AD7C0 */
/* sym: ?func_00011C90_1@Object_000ACFB0@@UAEXXZ = 0x000ADD20 */
/* sym: ?func_00011C80@Object_000ACFB0@@UAEXH@Z = 0x000AD040 */
/* sym: ?func_00011C90_2@Object_000ACFB0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_3@Object_000ACFB0@@UAEXXZ = 0x000AEE80 */
/* sym: ?func_00011C80_1@Object_000ACFB0@@UAEXH@Z = 0x000AE660 */
/* sym: ?func_00011C80_3@Object_000ACFB0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000ACFB0@@UAEXH@Z = 0x000B3DE0 */
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

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD6E8).
struct Object_000ACFB0 : Node {
    virtual ~Object_000ACFB0();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_040[0xc4];
    int registered;
    Item_00017940 *item;
    char unknown_10c[0x2c];
    void *second;
    char unknown_13c[0x3c];
    void *first;
};

// Frees the buffers at 0x178 and 0x138 when there are any, then unregisters the item at 0x108 (func_000178D0 of
// data_0022FCE8) when the field at 0x104 is set.
Object_000ACFB0::~Object_000ACFB0()
{
    if (first) {
        operator delete(first);
    }
    if (second) {
        operator delete(second);
    }
    if (registered) {
        data_0022FCE8.func_000178D0(item);
    }
}
