/* sym: ??1Object_000A6980@@UAE@XZ = 0x000A6110 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000A6980@@UAEXXZ = 0x000A76E0 */
/* sym: ?func_00011C90_2@Object_000A6980@@UAEXXZ = 0x000AECC0 */
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
    void func_00065E50(Item_00065E50 *item);
};

extern Object_00039A10 data_001FB820;

struct Model_000A6110 {
    char unknown_0;
    unsigned char flags;
};

// A direct child of Node (table 0x1CD570, constructor func_000A6980); slot 1 is func_000A76E0.
struct Object_000A6980 : Node {
    virtual ~Object_000A6980();
    virtual void func_00011C90();
    virtual void func_00011C90_2();

    char unknown_040[0x18];
    Model_000A6110 *model;
    char unknown_05c[0x1c];
    Item_00065E50 *item;
    char unknown_07c[0x838];
    int mode;
};

// In mode 2 sets bit 7 of the second flag byte of the model at 0x58; hands the item at 0x78, when there is one,
// back to data_001FB820 (func_00065E50).
Object_000A6980::~Object_000A6980()
{
    switch (mode) {
    case 2:
        model->flags |= 0x80;
    }
    if (item) {
        data_001FB820.func_00065E50(item);
        item = 0;
    }
}
