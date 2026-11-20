/* sym: ??1Object_000A8B50@@UAE@XZ = 0x000A8B50 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000A8B50@@UAEXXZ = 0x000A9830 */
/* sym: ?func_00011C90_1@Object_000A8B50@@UAEXXZ = 0x000A8C00 */
/* sym: ?func_00011C80@Object_000A8B50@@UAEXH@Z = 0x000A9200 */
/* sym: ?func_00011C90_2@Object_000A8B50@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_3@Object_000A8B50@@UAEXXZ = 0x000AEE80 */
/* sym: ?func_00011C80_1@Object_000A8B50@@UAEXH@Z = 0x000AE660 */
/* sym: ?func_00011C80_3@Object_000A8B50@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000A8B50@@UAEXH@Z = 0x000B3DE0 */
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

struct Entry_000A8B50 {
    char unknown_000[0x50];
    int handle;
    char unknown_054[0x150];
    void *buffer;
    char unknown_1a8[0x18];
    Item_00017940 *item;
    char unknown_1c4[8];
};

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD608).
struct Object_000A8B50 : Node {
    virtual ~Object_000A8B50();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_040[4];
    Entry_000A8B50 *entries;
    unsigned int count;
};

// For each of the entries at 0x44: frees its buffer, and unregisters its item (func_000178D0 of data_0022FCE8)
// when its handle is not -1; then frees the entries.
Object_000A8B50::~Object_000A8B50()
{
    if (entries) {
        for (unsigned int i = 0; i < count; i++) {
            if (entries[i].buffer) {
                operator delete(entries[i].buffer);
            }
            if (entries[i].handle != -1) {
                data_0022FCE8.func_000178D0(entries[i].item);
            }
        }
        delete[] entries;
    }
}
