extern "C" void *memset(void *destination, int value, unsigned int size);

struct Desc_000A6B10;

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

struct Item_00065E50;

struct Object_00039A10 {
    Item_00065E50 *func_00065CB0(void *data, int count, int first, int second);
    void func_00065E50(Item_00065E50 *item);
};

extern Object_00039A10 data_001FB820;

struct Model_000A6110 {
    char unknown_0;
    unsigned char flags;
};

// What an entry's source (+0x30) holds for func_00065CB0.
struct Source_000A61C0 {
    char unknown_00[8];
    void *data;
    int count;
};

// The entry the object follows: its kind (+0x0), a flag at 0x28, its model (+0x2c) and source (+0x30).
struct Entry_000A61C0 {
    int kind;
    char unknown_04[0x24];
    int active;
    Model_000A6110 *model;
    Source_000A61C0 *source;
};

// A direct child of Node (table 0x1CD570, constructor func_000A6980); slot 1 is func_000A76E0.
struct Object_000A6980 : Node {
    virtual ~Object_000A6980();

    char unknown_040[4];
    int value_044[2];
    int value_04c;
    int value_050;
    char unknown_054[4];
    Model_000A6110 *model;
    char unknown_05c[0x14];
    Source_000A61C0 *source;
    char unknown_074[4];
    Item_00065E50 *item;
    int value_07c;
    char unknown_080[0x824];
    int first;
    int second;
    char unknown_8ac[8];
    int mode;
    char unknown_8b8[0x18];
    Entry_000A61C0 *entry;
    int ownerId;
    char unknown_8d8[4];
    int value_8dc;

    void func_000A61C0(Entry_000A61C0 *entry);
    void func_000A6B10(Desc_000A6B10 *desc);
};

// Takes on an entry by its own mode: 1 and 2 take the entry's model (2 also clears the flag at 0x28 of the entry at
// 0x8d0); 4 takes its source, hands back the item at 0x78 (func_00065E50 of data_001FB820) and makes a new one from the
// source with the values at 0x8a4/0x8a8 (func_00065CB0). Then clears 0x44/0x48 and 0x8dc and sets 0x50.
void Object_000A6980::func_000A61C0(Entry_000A61C0 *entry)
{
    switch (mode) {
    case 1:
        model = entry->model;
        break;
    case 2:
        this->entry->active = 0;
        model = entry->model;
        break;
    case 4:
        source = entry->source;
        if (item) {
            data_001FB820.func_00065E50(item);
            item = 0;
        }
        if (source->data) {
            item = data_001FB820.func_00065CB0(source->data, source->count, first, second);
        }
        break;
    }
    memset(value_044, 0, sizeof value_044);
    value_050 = 1;
    value_8dc = 0;
}
