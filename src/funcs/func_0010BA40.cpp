/* sym: ??1Object_0010BA40@@UAE@XZ = 0x0010BA40 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_0010BA40@@UAEXXZ = 0x0010BA50 */
/* sym: ?func_00011C80@Object_0010BA40@@UAEXH@Z = 0x0010BF90 */
/* sym: ?func_00011C90_2@Object_0010BA40@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_4@Object_0010BA40@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_6@Object_0010BA40@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_8@Object_0010BA40@@UAEXXZ = 0x000AECC0 */
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

// A direct child of Node (table 0x1D2120) whose destructor does nothing of its own.
struct Object_0010BA40 : Node {
    virtual ~Object_0010BA40();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();
};

Object_0010BA40::~Object_0010BA40()
{
}
