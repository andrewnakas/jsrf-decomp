/* sym: ??1Object_0011FC00@@UAE@XZ = 0x0011FC00 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_0011FC00@@UAEXXZ = 0x0011FC10 */
/* sym: ?func_00011C80@Object_0011FC00@@UAEXH@Z = 0x0011FEB0 */
/* sym: ?func_00011C90_4@Object_0011FC00@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_2@Object_0011FC00@@UAEXH@Z = 0x000B3DE0 */
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

// The class whose table is at 0x1D9090: overrides slots 1, 3, 7, 9 of Node.
struct Object_0011FC00 : Node {
    virtual ~Object_0011FC00();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);
};

Object_0011FC00::~Object_0011FC00()
{
}
