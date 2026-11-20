/* sym: ??0Object_00095FC0@@QAE@PAUNode@@HI@Z = 0x00095FC0 */
/* sym: ??1Object_00095FC0@@UAE@XZ = 0x00095FF0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ?func_00011C90_1@Object_00095FC0@@UAEXXZ = 0x00096070 */
/* sym: ?func_00011C90_3@Object_00095FC0@@UAEXXZ = 0x00096F60 */
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


// One of six direct children of Node (table 0x1CD2E0, destructor func_00095FF0): overrides slots 2 and 5.
struct Object_00095FC0 : Node {
    Object_00095FC0(Node *owner, int id, unsigned int flags);
    virtual ~Object_00095FC0();
    virtual void func_00011C90_1();
    virtual void func_00011C90_3();

    int unknown_40;
    int active;
    int unknown_48;
    int unknown_4c;
    int key;
};

Object_00095FC0::Object_00095FC0(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
{
    active = 0;
    unknown_48 = 0;
    unknown_4c = 0;
}
