/* sym: ??1Object_00050850@@UAE@XZ = 0x00050850 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_00050850@@UAEXXZ = 0x00050860 */
/* sym: ?func_00011C80@Object_00050850@@UAEXH@Z = 0x00050A30 */
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
    char unknown_34[0x10];
};

// A node with no virtual functions of its own (table 0x1C43D8 repeats Node's slots 1 to 15) and mask 7.
struct Object_00012170 : Node {
    Object_00012170(Node *owner, int id, unsigned int flags);

    char unknown_44[0x50];
    int unknown_94;
};

// The class whose table is at 0x1CAC60: overrides slots 1 (50860), 3 (50A30).
struct Object_00050850 : Object_00012170 {
    virtual ~Object_00050850();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
};

Object_00050850::~Object_00050850()
{
}
