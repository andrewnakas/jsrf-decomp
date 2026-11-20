/* sym: ??1Object_001112A0@@UAE@XZ = 0x001112A0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_001112A0@@UAEXXZ = 0x001117B0 */
/* sym: ?func_00011C80@Object_001112A0@@UAEXH@Z = 0x00111320 */
/* sym: ?func_00011C90_2@Object_001112A0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_1@Object_001112A0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_4@Object_001112A0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_2@Object_001112A0@@UAEXH@Z = 0x000B3DE0 */
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
    char unknown_34[0x60];
};

struct Game {
    void func_00012AC0(int first, int second);
    void func_000126D0(int which);
};

extern Game *data_0022FCE0;
void func_00118780(int value);

// The class whose table is at 0x1D2788: overrides slots 1, 3 of Node; slots 4, 6, 7, 9 hold folded thunks.
struct Object_001112A0 : Node {
    virtual ~Object_001112A0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);
};

// Before Node's destructor: func_00012AC0(0x72b1, 0) and func_000126D0(0) on the game, then func_00118780(0).
Object_001112A0::~Object_001112A0()
{
    data_0022FCE0->func_00012AC0(0x72b1, 0);
    data_0022FCE0->func_000126D0(0);
    func_00118780(0);
}
