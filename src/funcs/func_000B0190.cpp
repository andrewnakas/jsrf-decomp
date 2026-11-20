/* sym: ??1Object_000B0190@@UAE@XZ = 0x000B0190 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000B0190@@UAEXXZ = 0x000B0210 */
/* sym: ?func_00011C90_1@Object_000B0190@@UAEXXZ = 0x000B0600 */
/* sym: ?func_00011C80@Object_000B0190@@UAEXH@Z = 0x000B06E0 */
/* sym: ?func_00011C90_2@Object_000B0190@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_3@Object_000B0190@@UAEXXZ = 0x000AEE80 */
/* sym: ?func_00011C80_1@Object_000B0190@@UAEXH@Z = 0x000AE660 */
/* sym: ?func_00011C80_3@Object_000B0190@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000B0190@@UAEXH@Z = 0x000B3DE0 */
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

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD7F8).
struct Object_000B0190 : Node {
    virtual ~Object_000B0190();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_040[0x3c];
    int handle;
    char unknown_080[0x1e8];
    void *buffer;
    char unknown_26c[0x18];
    Item_00017940 *item;
};

// Frees the buffer at 0x268 when there is one, then unregisters the item at 0x284 (func_000178D0 of
// data_0022FCE8) when the handle at 0x7c is not -1.
Object_000B0190::~Object_000B0190()
{
    if (buffer) {
        operator delete(buffer);
    }
    if (handle != -1) {
        data_0022FCE8.func_000178D0(item);
    }
}
