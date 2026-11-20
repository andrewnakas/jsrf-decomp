/* sym: ??0Object_000A6980@@QAE@PAUNode@@HIPAUDesc_000A6B10@@@Z = 0x000A6980 */
/* sym: ??1Object_000A6980@@UAE@XZ = 0x000A6110 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??0Object_000A1C50@@QAE@PAUNode@@HIPAUDesc_000A6B10@@@Z = 0x00084200 */
/* sym: ?func_00011C90@Object_000A6980@@UAEXXZ = 0x000A76E0 */
/* sym: ?func_00011C90_2@Object_000A6980@@UAEXXZ = 0x000AECC0 */
struct Desc_000A6B10;

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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};

// What func_000A8370 hands func_000A6980/func_000A6B10: an entry, a kind (4: no id of its own), a value, the id
// the object takes (written back at 0x18) and two values for the entry's item.
struct Entry_000A61C0;

struct Desc_000A6B10 {
    Entry_000A61C0 *entry;
    char unknown_04[8];
    int value_0c;
    int kind;
    int value;
    int id;
    int first;
    int second;
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
    Object_000A6980(Node *owner, int id, unsigned int flags, Desc_000A6B10 *desc);
    virtual ~Object_000A6980();
    virtual void func_00011C90();
    virtual void func_00011C90_2();

    char unknown_040[4];
    int value_044[2];
    int value_04c;
    int value_050;
    char unknown_054[4];
    Model_000A6110 *model;
    char unknown_05c[0xc];
    int value_068;
    int value_06c;
    Source_000A61C0 *source;
    int value_074;
    Item_00065E50 *item;
    int value_07c;
    int value_080;
    int value_084;
    int value_088;
    char unknown_08c[0x818];
    int first;
    int second;
    int value_8ac;
    int value_8b0;
    int mode;
    int value_8b8;
    char unknown_8bc[0x14];
    Entry_000A61C0 *entry;
    int ownerId;
    int id;
    int value_8dc;
    int value_8e0;
    int value_8e4;

    void func_000A61C0(Entry_000A61C0 *entry);
    void func_000A6B10(Desc_000A6B10 *desc);
};

struct Game {
    int func_000127E0(int index);
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

// The player (0x1178 bytes).
struct Object_000A1C50 : Node {
    Object_000A1C50(Node *owner, int id, unsigned int flags, Desc_000A6B10 *desc);

    char unknown_040[0x1138];
};

// Builds the Node part and follows the description's entry: takes an id from 0x4c-0x4f unless the kind is 4 (-1) and
// writes it back into the description, takes an owner id from 0x2c-0x4b and creates the player there with the
// description (func_00084200), then takes the entry on (func_000A61C0) and keeps value 0x173 + its first value
// (func_000127E0) at 0x8b8.
Object_000A6980::Object_000A6980(Node *owner, int id, unsigned int flags, Desc_000A6B10 *desc) : Node(owner, id, flags)
{
    entry = desc->entry;
    if (desc->kind != 4) {
        this->id = data_0022FCE0->func_000128E0(0x4c, 0x4f);
    } else {
        this->id = -1;
    }
    desc->id = this->id;
    ownerId = data_0022FCE0->func_000128E0(0x2c, 0x4b);
    new Object_000A1C50(this, ownerId, flags, desc);
    mode = desc->entry->kind;
    value_8ac = desc->value_0c;
    value_8b0 = 0;
    first = desc->first;
    second = desc->second;
    value_04c = 0;
    source = 0;
    value_074 = 0;
    item = 0;
    value_080 = -1;
    value_084 = -1;
    value_088 = -1;
    value_07c = desc->value;
    func_000A61C0(desc->entry);
    value_8b8 = data_0022FCE0->func_000127E0(first + 0x173);
    value_068 = 0;
    value_8e0 = 0;
    value_8e4 = 0;
    value_06c = 0;
}
