/* sym: ??1Object_000F4A30@@UAE@XZ = 0x000F4A30 */
/* sym: ??1Object_000C7240@@UAE@XZ = 0x000C7240 */
/* sym: ?func_00011C90@Object_000C7240@@UAEXXZ = 0x000C9280 */
/* sym: ?func_00011C90_1@Object_000C7240@@UAEXXZ = 0x000C7330 */
/* sym: ?func_00011C80@Object_000C7240@@UAEXH@Z = 0x000C74B0 */
/* sym: ?func_00011C80_3@Object_000C7240@@UAEXH@Z = 0x000C7720 */
/* sym: ?func_00011C80_4@Object_000C7240@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_000C60C0@Object_000C7240@@UAEXXZ = 0x000C9EB0 */
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
    char unknown_34[0x10];
};

// The second base (table 0x1CE1B8), two slots.
struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

// The class whose tables are at 0x1CE1C8 (Node) and 0x1CE1C0 (Object_000C60C0 at +0x44); slot 15 holds a folded
// thunk.
struct Object_000C7240 : Node, Object_000C60C0 {
    virtual ~Object_000C7240();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);
    virtual void func_000C60C0();
};

// The class whose tables are at 0x1CF0E0 and 0x1CF0D8: overrides only the destructor of Object_000C7240.
struct Object_000F4A30 : Object_000C7240 {
    virtual ~Object_000F4A30();
};

Object_000F4A30::~Object_000F4A30()
{
}
