/* sym: ??0Object_000243F0@@QAE@PAUNode@@HI@Z = 0x00024670 */
/* const: 0x10002 */
/* sym: ??1Object_000243F0@@UAE@XZ = 0x000243F0 */
/* sym: ?func_00011C90@Object_000243F0@@UAEXXZ = 0x00024700 */
/* sym: ?func_00011C80@Object_000243F0@@UAEXH@Z = 0x00024400 */
/* sym: ?func_00011C90_2@Object_000243F0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_1@Object_000243F0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_4@Object_000243F0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_2@Object_000243F0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_6@Object_000243F0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_8@Object_000243F0@@UAEXXZ = 0x000AECC0 */
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

/* sym: ??0Object_00012170@@QAE@PAUNode@@HI@Z = 0x00012170 */

// The class whose table is at 0x1C4D10: overrides slots 1 (24700), 3 (24400), 4 (AECC0), 6 (B3DE0), 7 (AECC0), 9 (B3DE0), 10 (AECC0), 13 (AECC0).
struct Object_000243F0 : Object_00012170 {
    virtual ~Object_000243F0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();

    Object_000243F0(Node *owner, int id, unsigned int flags);

    int unknown_98[4];
    int unknown_a8[4];
    float unknown_b8;
    unsigned int color;
    int unknown_c0;
};

Object_000243F0::Object_000243F0(Node *owner, int id, unsigned int flags) : Object_00012170(owner, id, flags)
{
    this->flags |= 0x10002;
    sortKey = 10;
    for (int i = 0; i < 4; i++) {
        unknown_98[i] = 0;
        unknown_a8[i] = 0;
    }
    color = 0;
    unknown_c0 = 1;
    unknown_b8 = 0.016666668f;
}
