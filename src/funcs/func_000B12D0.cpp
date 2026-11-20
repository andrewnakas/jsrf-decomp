/* sym: ?func_00011C90_1@Object_000B1130@@UAEXXZ = 0x000B12D0 */
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
struct Entry_000B1130 {
    int used;
    int kind;
    char unknown_008[0x3c];
    int handle;
    char unknown_048[0x2c];
    int value_74;
    int value_78;
    int value_7c;
    char unknown_080[0x24];
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
    void *item;
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

// The entries' second handlers by kind (func_000B2270, func_00011C80, func_000B2B60).
extern void (Object_000B1130::*data_00215D54[3])(int index);

// Overrides slot 2: runs the second handler of each used entry's kind (data_00215D54) with its index and clears
// the entry's fields at 0x74, 0x78 and 0x7c.
void Object_000B1130::func_00011C90_1()
{
    for (unsigned int i = 0; i < count; i++) {
        if (entries[i].used) {
            (this->*data_00215D54[entries[i].kind])(i);
            entries[i].value_74 = 0;
            entries[i].value_78 = 0;
            entries[i].value_7c = 0;
        }
    }
}
