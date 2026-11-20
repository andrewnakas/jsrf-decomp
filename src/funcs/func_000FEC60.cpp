/* sym: ??1Object_000FEDB0@@UAE@XZ = 0x000FEC60 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000FEDB0@@UAEXXZ = 0x000FECC0 */
/* sym: ?func_00011C90_1@Object_000FEDB0@@UAEXXZ = 0x000FEDB0 */
/* sym: ?func_00011C80@Object_000FEDB0@@UAEXH@Z = 0x000FEDC0 */
/* sym: ?func_00011C80_1@Object_000FEDB0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_2@Object_000FEDB0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_3@Object_000FEDB0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000FEDB0@@UAEXH@Z = 0x000B3DE0 */
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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

// The camera node (constructor func_00012170): its table repeats Node's slots; its implicit destructor is at
// 0x121D0.
struct Object_00012170 : Node {
    char unknown_040[0x58];
};

// The child of the camera node whose table is at 0x1D1C30 (constructor func_000FF230; object 0x1163).
struct Object_000FEDB0 : Object_00012170 {
    virtual ~Object_000FEDB0();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);
};

// Takes itself out of the draw links (func_00011BE0) and does the same for its children (func_00011C20).
Object_000FEDB0::~Object_000FEDB0()
{
    func_00011BE0(this);
    func_00011C20(child);
}
