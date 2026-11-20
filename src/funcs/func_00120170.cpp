/* sym: ??1Object_00120170@@UAE@XZ = 0x00120170 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C80@Object_00120170@@UAEXH@Z = 0x00120180 */
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

// The class whose table is at 0x1D90D0: overrides slot 3 of Node. Its constructor (0x120370)
// builds it on Object_00012170, whose implicit destructor is inlined here: the jump goes straight to Node's.
struct Object_00120170 : Node {
    virtual ~Object_00120170();
    virtual void func_00011C80(int argument);
};

Object_00120170::~Object_00120170()
{
}
