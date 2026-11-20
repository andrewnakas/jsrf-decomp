/* sym: ??0Object_00137390@@QAE@PAUNode@@HI@Z = 0x001374F0 */
/* sym: ??0Object_00012170@@QAE@PAUNode@@HI@Z = 0x00012170 */
/* sym: ??1Object_00137390@@UAE@XZ = 0x00137390 */
/* sym: ??1Object_00012170@@UAE@XZ = 0x000121D0 */
/* sym: ?func_00011C80@Object_00137390@@UAEXH@Z = 0x001373A0 */
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

// A node with no virtual functions of its own (table 0x1C43D8 repeats Node's slots 1 to 15) and mask 7. Its
// destructor (0x121D0, implicit in its own unit) is what this constructor's unwind code calls.
struct Object_00012170 : Node {
    Object_00012170(Node *owner, int id, unsigned int flags);
    virtual ~Object_00012170();

    int unknown_94;
};

// The class whose table is at 0x1DE9E0: overrides slot 3 of Node.
struct Object_00137390 : Object_00012170 {
    Object_00137390(Node *owner, int id, unsigned int flags);
    virtual ~Object_00137390();
    virtual void func_00011C80(int argument);

    void func_00137470();
};

Object_00137390::Object_00137390(Node *owner, int id, unsigned int flags) : Object_00012170(owner, id, flags)
{
    func_00137470();
}
