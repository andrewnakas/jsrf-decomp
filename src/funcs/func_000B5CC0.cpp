/* sym: ??1Object_000B5CC0@@UAE@XZ = 0x000B5CC0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000B5CC0@@UAEXXZ = 0x000B5E70 */
/* sym: ?func_00011C80@Object_000B5CC0@@UAEXH@Z = 0x000B5EB0 */
/* sym: ?func_00011C90_2@Object_000B5CC0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_1@Object_000B5CC0@@UAEXH@Z = 0x000AE660 */
/* sym: ?func_00011C80_3@Object_000B5CC0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000B5CC0@@UAEXH@Z = 0x000B3DE0 */
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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};
struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    void func_000607B0(int key);
};

struct Item_00017940;

struct Object_00016200 {
    void func_000178D0(Item_00017940 *item);
    void func_0001B400(int key);
};

extern Object_00016200 data_0022FCE8;

struct Entry_000B5CC0 {
    int used;
    char unknown_004[0xf4];
    int sounds[16];
    char unknown_138[4];
    unsigned int keyCount;
    int *keys;
    char unknown_144[0xb4];
    int ids[16];
    int registered;
    Item_00017940 *item;
    char unknown_240[8];
};

// One of 17 direct children of Node that share slots 4, 6, 12 and 15 (table 0x1CD910).
struct Object_000B5CC0 : Node {
    virtual ~Object_000B5CC0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_040[4];
    Entry_000B5CC0 *entries;
    unsigned int count;
};

// For each of the entries at 0x44 that is in use: unregisters its item (func_000178D0 of data_0022FCE8) when it
// is registered, unlinks the nodes its 16 ids name (func_00011BE0, then func_00011C20 on the node's child),
// passes its 16 keys that are not -1 to object 0xe8 (func_000607B0) when it exists, and passes each of its other
// keys to func_0001B400 of data_0022FCE8 before freeing them; then frees the entries.
Object_000B5CC0::~Object_000B5CC0()
{
    if (entries) {
        for (unsigned int i = 0; i < count; i++) {
            if (entries[i].used) {
                if (entries[i].registered) {
                    data_0022FCE8.func_000178D0(entries[i].item);
                }
                for (int n = 0; n < 16; n++) {
                    if (entries[i].ids[n]) {
                        Node *node = (Node *)data_0022FCE0->func_000128C0(entries[i].ids[n]);
                        if (node) {
                            node->func_00011BE0(node);
                            node->func_00011C20(node->child);
                        }
                    }
                }
                Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
                if (object) {
                    for (int s = 0; s < 16; s++) {
                        if (entries[i].sounds[s] != -1) {
                            object->func_000607B0(entries[i].sounds[s]);
                        }
                    }
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
