/* sym: ??0Object_00120170@@QAE@PAUNode@@HI@Z = 0x00120370 */
/* sym: ??0Object_00012170@@QAE@PAUNode@@HI@Z = 0x00012170 */
/* sym: ??1Object_00120170@@UAE@XZ = 0x00120170 */
/* sym: ??1Object_00012170@@UAE@XZ = 0x000121D0 */
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

// A node with no virtual functions of its own (table 0x1C43D8 repeats Node's slots 1 to 15) and mask 7. Its
// destructor (0x121D0, implicit in its own unit) is what this constructor's unwind code calls.
struct Object_00012170 : Node {
    Object_00012170(Node *owner, int id, unsigned int flags);
    virtual ~Object_00012170();

    int unknown_94;
};

// The class whose table is at 0x1D90D0: overrides slot 3 of Node.
struct Object_00120170 : Object_00012170 {
    Object_00120170(Node *owner, int id, unsigned int flags);
    virtual ~Object_00120170();
    virtual void func_00011C80(int argument);

    void func_001202E0();

    char unknown_098[0x6c];
    int value_104;
    int value_108;
    float value_10c;
    int value_110;
    int value_114;
    float value_118;
};

Object_00120170::Object_00120170(Node *owner, int id, unsigned int flags) : Object_00012170(owner, id, flags)
{
    func_001202E0();
    value_104 = 0;
    value_108 = 0;
    value_110 = 0;
    value_114 = 0;
    value_10c = 3001.0f;
    value_118 = 3000.0f;
}
