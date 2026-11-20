/* sym: ??1Object_000F44E0@@UAE@XZ = 0x000F3F70 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000F44E0@@UAEXXZ = 0x000F4480 */
/* sym: ?func_00011C90_1@Object_000F44E0@@UAEXXZ = 0x000F44E0 */
/* sym: ?func_00011C80@Object_000F44E0@@UAEXH@Z = 0x000F3FE0 */
/* sym: ?func_00011C80_3@Object_000F44E0@@UAEXH@Z = 0x000F4050 */
/* sym: ?func_00011C80_4@Object_000F44E0@@UAEXH@Z = 0x000B3DE0 */
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
    void func_00019760(void *item);
};

extern Object_00016200 data_0022FCE8;

int func_001186D0(int handle);

// The child of Node whose table is at 0x1CF098 (constructor func_000F3E60).
struct Object_000F44E0 : Node {
    virtual ~Object_000F44E0();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_040[0xac];
    void *item;
    char unknown_0f0[0x18];
    int handle;
};

// Passes the value at 0x108 to func_001186D0, then hands the item at 0xec, when there is one, to func_00019760 of
// data_0022FCE8.
Object_000F44E0::~Object_000F44E0()
{
    func_001186D0(handle);
    if (item) {
        data_0022FCE8.func_00019760(item);
    }
}
