/* sym: ??1Object_000F7280@@UAE@XZ = 0x000F7320 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000F7280@@UAEXXZ = 0x000F7390 */
/* sym: ?func_00011C80@Object_000F7280@@UAEXH@Z = 0x000F73D0 */
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
struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Object 0x1163.
struct Object_000FEC10 {
    char unknown_000[0x130];
    int value_130;
};

// The child of Node whose table is at 0x1CF2F8 (constructor func_000F7280).
struct Object_000F7280 : Node {
    virtual ~Object_000F7280();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
};

// Clears the value at 0x130 of object 0x1163.
Object_000F7280::~Object_000F7280()
{
    ((Object_000FEC10 *)data_0022FCE0->func_000128C0(0x1163))->value_130 = 0;
}
