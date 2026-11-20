/* sym: ??1Object_000C0A90@@UAE@XZ = 0x000C0D90 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000C0A90@@UAEXXZ = 0x000C0470 */
/* sym: ?func_00011C90_1@Object_000C0A90@@UAEXXZ = 0x000C0490 */
/* sym: ?func_00011C80@Object_000C0A90@@UAEXH@Z = 0x000C04A0 */
/* sym: ?func_00011C90_6@Object_000C0A90@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_7@Object_000C0A90@@UAEXXZ = 0x000AEE80 */
/* sym: ?func_00011C80_3@Object_000C0A90@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000C0A90@@UAEXH@Z = 0x000B3DE0 */
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

// A direct child of Node (table 0x1CDC18; constructor func_000C0A90, destructor func_000C0D90).
struct Object_000C0A90 : Node {
    virtual ~Object_000C0A90();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C90_7();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    void func_000C0AC0();
};

// Runs func_000C0AC0 first.
Object_000C0A90::~Object_000C0A90()
{
    func_000C0AC0();
}
