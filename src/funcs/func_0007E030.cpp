/* sym: ??1Object_0007E010@@UAE@XZ = 0x0007E010 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C80@Object_0007E010@@UAEXH@Z = 0x0007E020 */
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

/* sym: ??0Object_0007E010@@QAE@PAUNode@@HI@Z = 0x0007E030 */
/* sym: ??0Object_00012170@@QAE@PAUNode@@HI@Z = 0x00012170 */
/* sym: ??0Object_0007C250@@QAE@PAUNode@@HI@Z = 0x0007D5D0 */

struct Object_0007C250 : Node {
    Object_0007C250(Node *owner, int id, unsigned int flags);
    char unknown_44[0x40];
};

// The class whose table is at 0x1CCF38: overrides slots 3 (7E020).
struct Object_0007E010 : Object_00012170 {
    virtual ~Object_0007E010();
    virtual void func_00011C80(int argument);

    Object_0007E010(Node *owner, int id, unsigned int flags);
};

// Creates its child 0x1DD9 (the class of 0x7D5D0).
Object_0007E010::Object_0007E010(Node *owner, int id, unsigned int flags) : Object_00012170(owner, id, flags)
{
    new Object_0007C250(this, 0x1dd9, 0x80);
}
