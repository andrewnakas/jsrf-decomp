/* sym: ??1Object_00115900@@UAE@XZ = 0x00115900 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_00115900@@UAEXXZ = 0x00113CD0 */
/* sym: ?func_00011C90_2@Object_00115900@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_4@Object_00115900@@UAEXXZ = 0x00115910 */
/* sym: ?func_00011C80_2@Object_00115900@@UAEXH@Z = 0x00115A40 */
/* sym: ?func_00011C90_6@Object_00115900@@UAEXXZ = 0x000AECC0 */
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

// The class whose table is at 0x1D2BB0: overrides slots 1, 7, 9 of Node; slots 4, 10 hold folded thunks.
struct Object_00115900 : Node {
    virtual ~Object_00115900();
    virtual void func_00011C90();
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
};

Object_00115900::~Object_00115900()
{
}
