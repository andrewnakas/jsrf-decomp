/* sym: ??1Object_00072710@@UAE@XZ = 0x00072710 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_00072710@@UAEXXZ = 0x000720B0 */
/* sym: ?func_00011C80@Object_00072710@@UAEXH@Z = 0x00072760 */
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

struct Object_000667D0 {
    void func_000667D0();
};

extern Object_000667D0 *data_00251F24;

/* sym: ??0Object_00072710@@QAE@PAUNode@@HI@Z = 0x000726A0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */

// The class whose table is at 0x1CCAE0: overrides slots 1 (720B0), 3 (72760).
struct Object_00072710 : Node {
    virtual ~Object_00072710();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);

    Object_00072710(Node *owner, int id, unsigned int flags);

    int unknown_44;

    void func_00072370();
    void func_000723B0();
};

// Clears +0x44, runs func_00072370 and func_000667D0 of the object at 0x251F24.
Object_00072710::Object_00072710(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
{
    unknown_44 = 0;
    func_00072370();
    data_00251F24->func_000667D0();
}
