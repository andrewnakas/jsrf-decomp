/* sym: ??1Object_000F97D0@@UAE@XZ = 0x000F9820 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000F97D0@@UAEXXZ = 0x000F9830 */
/* sym: ?func_00011C80@Object_000F97D0@@UAEXH@Z = 0x00115F40 */
/* sym: ?func_00011C90_2@Object_000F97D0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_1@Object_000F97D0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_4@Object_000F97D0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_2@Object_000F97D0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_6@Object_000F97D0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_3@Object_000F97D0@@UAEXH@Z = 0x000B3DE0 */
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

// A direct child of Node (table 0x1D07F8, constructor func_000F97D0) whose destructor does nothing of its own.
struct Object_000F97D0 : Node {
    virtual ~Object_000F97D0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C80_3(int argument);
};

Object_000F97D0::~Object_000F97D0()
{
}
