/* sym: ??1Object_00135130@@UAE@XZ = 0x00135130 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C80@Object_00135130@@UAEXH@Z = 0x00135140 */
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

// The class whose table is at 0x1DE938: overrides slot 3 of Node. Its constructor (0x135290)
// builds it on Object_00012170, whose implicit destructor is inlined here: the jump goes straight to Node's.
struct Object_00135130 : Node {
    virtual ~Object_00135130();
    virtual void func_00011C80(int argument);
};

Object_00135130::~Object_00135130()
{
}
