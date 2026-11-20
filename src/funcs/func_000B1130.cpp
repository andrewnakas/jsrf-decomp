/* sym: ??1Object_000B1130@@UAE@XZ = 0x000B1130 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000B1130@@UAEXXZ = 0x000B1290 */
/* sym: ?func_00011C90_1@Object_000B1130@@UAEXXZ = 0x000B12D0 */
/* sym: ?func_00011C80@Object_000B1130@@UAEXH@Z = 0x000B2D20 */
/* sym: ?func_00011C90_2@Object_000B1130@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_3@Object_000B1130@@UAEXXZ = 0x000AEE80 */
/* sym: ?func_00011C80_1@Object_000B1130@@UAEXH@Z = 0x000AE660 */
/* sym: ?func_00011C80_3@Object_000B1130@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000B1130@@UAEXH@Z = 0x000B3DE0 */
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
    void func_0001B400(int key);
};

extern Object_00016200 data_0022FCE8;

void func_0005DAA0(void *pointer);

struct Entry_000B1130 {
    int used;
    char unknown_004[0x40];
    int handle;
    char unknown_048[0x5c];
    void *block;
    char unknown_0a8[0xa4];
    unsigned int keyCount;
    int *keys;
    char unknown_154[0x24];
    void *first;
    char unknown_17c[0x3c];
    void *second;
    char unknown_1bc[0x14];
    int registered;
    Item_00017940 *item;
    char unknown_1d8[8];
};

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD838).
struct Object_000B1130 : Node {
    virtual ~Object_000B1130();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_040[4];
    Entry_000B1130 *entries;
    unsigned int count;
};

// For each of the entries at 0x44 that is in use: frees its two buffers, unregisters its item (func_000178D0 of
// data_0022FCE8) when its handle is not -1 and it is registered, passes its block to func_0005DAA0, and passes
// each of its keys to func_0001B400 of data_0022FCE8 before freeing them; then frees the entries.
Object_000B1130::~Object_000B1130()
{
    if (entries) {
        for (unsigned int i = 0; i < count; i++) {
            if (entries[i].used) {
                if (entries[i].first) {
                    operator delete(entries[i].first);
                }
                if (entries[i].second) {
                    operator delete(entries[i].second);
                }
                if (entries[i].handle != -1 && entries[i].registered) {
                    data_0022FCE8.func_000178D0(entries[i].item);
                }
                if (entries[i].block) {
                    func_0005DAA0(entries[i].block);
                }
                if (entries[i].keys) {
                    for (unsigned int k = 0; k < entries[i].keyCount; k++) {
                        data_0022FCE8.func_0001B400(entries[i].keys[k]);
                    }
                    delete[] entries[i].keys;
                }
            }
        }
        delete[] entries;
    }
}
