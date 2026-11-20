/* sym: ??1Object_001379E0@@UAE@XZ = 0x001379E0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_001379E0@@UAEXXZ = 0x0013A340 */
/* sym: ?func_00011C80@Object_001379E0@@UAEXH@Z = 0x0013A240 */
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

// The class whose table is at 0x1DEA60: overrides slots 1 and 3 of Node.
struct Object_001379E0 : Node {
    virtual ~Object_001379E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
};

Object_001379E0::~Object_001379E0()
{
}
