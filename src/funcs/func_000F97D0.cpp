/* sym: ??0Object_000F97D0@@QAE@PAUNode@@HIMMMH@Z = 0x000F97D0 */
/* sym: ??1Object_000F97D0@@UAE@XZ = 0x000F9820 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ?func_00011C90@Object_000F97D0@@UAEXXZ = 0x000F9830 */
/* sym: ?func_00011C80@Object_000F97D0@@UAEXH@Z = 0x00115F40 */
/* sym: ?func_00011C90_2@Object_000F97D0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_1@Object_000F97D0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_4@Object_000F97D0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_2@Object_000F97D0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_6@Object_000F97D0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_3@Object_000F97D0@@UAEXH@Z = 0x000B3DE0 */
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

// A direct child of Node (table 0x1D07F8, destructor func_000F9820): something that scrolls from x = 640 to the left
// by `speed` each frame and starts again once it is past its own width.
struct Object_000F97D0 : Node {
    Object_000F97D0(Node *owner, int id, unsigned int flags, float first, float second, float speed, int kind);
    virtual ~Object_000F97D0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C80_3(int argument);

    int unknown_040;
    int kind;
    float first;
    float second;
    int unknown_050;
    float x;
    float y;
    int unknown_05c;
    float speed;
    float width;
    int unknown_068;
    int phase;
    int unknown_070;
};

// Keeps the arguments (0x48, 0x4c, the speed at 0x60, the kind at 0x44) and clears 0x50, the phase and 0x70.
Object_000F97D0::Object_000F97D0(Node *owner, int id, unsigned int flags, float first, float second, float speed,
                                 int kind)
    : Node(owner, id, flags), first(first), second(second), unknown_050(0), speed(speed)
{
    this->kind = kind;
    phase = 0;
    unknown_070 = 0;
}
