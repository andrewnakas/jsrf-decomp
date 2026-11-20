/* sym: ??1Object_00050FE0@@UAE@XZ = 0x00050FE0 */
/* sym: ??1Object_00012170@@UAE@XZ = 0x000121D0 */
/* sym: ?func_00011C90_3@Object_00050FE0@@UAEXXZ = 0x00050FF0 */
/* sym: ?func_00011C80_1@Object_00050FE0@@UAEXH@Z = 0x00051130 */
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
    virtual ~Object_00012170();

    char unknown_44[0x50];
    int unknown_94;
};

/* sym: ??0Object_00050FE0@@QAE@PAUNode@@HI@Z = 0x00050F60 */
/* sym: ??0Object_00012170@@QAE@PAUNode@@HI@Z = 0x00012170 */

void *func_00025700(unsigned int index, int first, int second, int third);

// The class whose table is at 0x1CADA8: overrides slots 5 (50FF0), 6 (51130).
struct Object_00050FE0 : Object_00012170 {
    virtual ~Object_00050FE0();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);

    Object_00050FE0(Node *owner, int id, unsigned int flags);

    void *unknown_98;
    int unknown_9c;
};

Object_00050FE0::Object_00050FE0(Node *owner, int id, unsigned int flags) : Object_00012170(owner, id, flags)
{
    unknown_98 = func_00025700(0xb, 0, 5, 4);
    unknown_9c = 0;
}
