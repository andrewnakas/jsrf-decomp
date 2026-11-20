/* sym: ??0Object_0007AF80@@QAE@PAUNode@@HIPAUStep_0007AF80@@H@Z = 0x0007B850 */
/* sym: ??0Object_00012170@@QAE@PAUNode@@HI@Z = 0x00012170 */
/* sym: ??1Object_0007AF80@@UAE@XZ = 0x0007AF80 */
/* sym: ?func_00011C90@Object_0007AF80@@UAEXXZ = 0x0007AF90 */
/* sym: ?func_00011C80@Object_0007AF80@@UAEXH@Z = 0x0007B750 */
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

struct Step_0007AF80 {
    char unknown_00[0x30];
};

// The class whose table is at 0x1CCE70: walks a list of 0x30-byte steps. Overrides slots 1 and 3.
struct Object_0007AF80 : Object_00012170 {
    Object_0007AF80(Node *owner, int id, unsigned int flags, Step_0007AF80 *steps, int count);
    virtual ~Object_0007AF80();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);

    Step_0007AF80 *steps;
    int count;
    int index;
    int unknown_a4;
    int unknown_a8;
    int unknown_ac;
};

Object_0007AF80::Object_0007AF80(Node *owner, int id, unsigned int flags, Step_0007AF80 *steps, int count)
    : Object_00012170(owner, id, flags)
{
    this->steps = steps;
    this->count = count;
    index = 0;
    unknown_a4 = 0;
    unknown_a8 = 0;
    unknown_ac = 0;
}
