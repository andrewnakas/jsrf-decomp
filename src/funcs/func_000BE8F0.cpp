/* sym: ??1Object_000BE900@@UAE@XZ = 0x000BE8F0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90_1@Object_000BE900@@UAEXXZ = 0x000BE900 */
/* sym: ?func_00011C80@Object_000BE900@@UAEXH@Z = 0x000BE930 */
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

// The child of Node whose table is at 0x1CDB60: overrides slots 2 and 3.
struct Object_000BE900 : Node {
    virtual ~Object_000BE900();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int message);
};

Object_000BE900::~Object_000BE900()
{
}
