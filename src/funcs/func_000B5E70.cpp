/* sym: ?func_00011C90@Object_000B5CC0@@UAEXXZ = 0x000B5E70 */
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

struct Entry_000B5CC0 {
    int used;
    char unknown_004[0xc];
    int kind;
    char unknown_014[0xe4];
    int sounds[16];
    char unknown_138[4];
    unsigned int keyCount;
    int *keys;
    char unknown_144[0xb4];
    int ids[16];
    int registered;
    void *item;
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

// The entries' handlers by kind (func_000B6760, func_000B6ED0).
extern void (Object_000B5CC0::*data_00215D60[])(int index);

// Overrides slot 1: runs the handler of each used entry's kind (data_00215D60, the kind at 0x10) with its index.
void Object_000B5CC0::func_00011C90()
{
    for (unsigned int i = 0; i < count; i++) {
        if (entries[i].used) {
            (this->*data_00215D60[entries[i].kind])(i);
        }
    }
}
