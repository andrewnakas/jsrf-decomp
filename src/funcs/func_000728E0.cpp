/* sym: ??1Object_000728C0@@UAE@XZ = 0x000728C0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000728C0@@UAEXXZ = 0x000728D0 */
/* sym: ?func_00011C80@Object_000728C0@@UAEXH@Z = 0x0007E020 */
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

/* sym: ??0Object_000728C0@@QAE@PAUNode@@HI@Z = 0x000728E0 */
/* sym: ??0Object_00012170@@QAE@PAUNode@@HI@Z = 0x00012170 */
/* sym: ??0Object_00072710@@QAE@PAUNode@@HI@Z = 0x000726A0 */

struct Object_00072710 : Node {
    Object_00072710(Node *owner, int id, unsigned int flags);
    char unknown_44[0x48];
};

// The class whose table is at 0x1CCB28: overrides slots 1 (728D0), 3 (7E020).
struct Object_000728C0 : Object_00012170 {
    virtual ~Object_000728C0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);

    Object_000728C0(Node *owner, int id, unsigned int flags);
};

// Creates its child 0x1DEE (the class of 0x726A0).
Object_000728C0::Object_000728C0(Node *owner, int id, unsigned int flags) : Object_00012170(owner, id, flags)
{
    new Object_00072710(this, 0x1dee, 0x80);
}
