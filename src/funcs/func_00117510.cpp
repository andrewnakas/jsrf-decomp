/* sym: ??1Object_00117510@@UAE@XZ = 0x00117510 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_00117510@@UAEXXZ = 0x001178B0 */
/* sym: ?func_00011C90_2@Object_00117510@@UAEXXZ = 0x00117750 */
/* sym: ?func_00011C90_4@Object_00117510@@UAEXXZ = 0x00023F10 */
/* sym: ?func_00011C90_6@Object_00117510@@UAEXXZ = 0x00023F10 */
/* sym: ?func_00011C90_8@Object_00117510@@UAEXXZ = 0x00023F10 */
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

void func_001168F0();

// The class whose table is at 0x1D7778: overrides slots 1, 4, 7, 10, 13 of Node.
struct Object_00117510 : Node {
    virtual ~Object_00117510();
    virtual void func_00011C90();
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();
};

// Stops the class's sound (func_001168F0) before Node's destructor runs.
Object_00117510::~Object_00117510()
{
    func_001168F0();
}
