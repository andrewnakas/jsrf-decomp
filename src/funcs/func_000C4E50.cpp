/* sym: ??1Object_000C4CF0@@UAE@XZ = 0x000C4E50 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000C4CF0@@UAEXXZ = 0x000C4EB0 */
/* sym: ?func_00011C90_1@Object_000C4CF0@@UAEXXZ = 0x000C5040 */
/* sym: ?func_00011C80@Object_000C4CF0@@UAEXH@Z = 0x000C5170 */
/* sym: ?func_00011C80_3@Object_000C4CF0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000C4CF0@@UAEXH@Z = 0x000B3DE0 */
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


struct Object_00016200 {
    void func_00019760(void *pointer);
};

extern Object_00016200 data_0022FCE8;

// The child of Node whose table is at 0x1CDE60 (constructor func_000C4CF0): it overrides slots 1, 2, 3, 12 and 15
// and adds three empty slots, 16 to 18.
struct Object_000C4CF0 : Node {
    virtual ~Object_000C4CF0();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);
    virtual void func_00011C90_10();
    virtual void func_00011C90_11();
    virtual void func_00011C90_12();

    char unknown_040[0xbc];
    void *item;
};

// Hands the item at 0xfc, when there is one, to func_00019760 of data_0022FCE8.
Object_000C4CF0::~Object_000C4CF0()
{
    if (item) {
        data_0022FCE8.func_00019760(item);
    }
}
