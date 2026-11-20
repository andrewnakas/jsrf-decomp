/* sym: ??1Object_0009C3C0@@UAE@XZ = 0x0009C400 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C80@Object_0009C3C0@@UAEXH@Z = 0x0009CBE0 */
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

// The child of Node whose table is at 0x1CD4A8: overrides slot 3 (the message handler at 0x9CBE0).
struct Object_0009C3C0 : Node {
    Object_0009C3C0(Node *owner, int id, unsigned int flags, int value);
    virtual ~Object_0009C3C0();
    virtual void func_00011C80(int message);

    char unknown_40[4];
    int value;
};

Object_0009C3C0::~Object_0009C3C0()
{
}
