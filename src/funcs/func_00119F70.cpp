/* sym: ??0Object_0011A020@@QAE@PAUNode@@HIHH@Z = 0x00119F70 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_0011A020@@UAE@XZ = 0x0011A020 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_0011A020@@UAEXXZ = 0x0011A030 */
/* sym: ?func_00011C80@Object_0011A020@@UAEXH@Z = 0x0011A070 */
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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);

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

struct Sprite_00119F70 {
    char unknown_00[0x24];
    unsigned int flags;
};

struct Vector3 {
    float x;
    float y;
    float z;
};

void *func_00025700(unsigned int index, int first, int second, int third);

// The class whose table is at 0x1D7BA0.
struct Object_0011A020 : Node {
    Object_0011A020(Node *owner, int id, unsigned int flags, int first, int second);
    virtual ~Object_0011A020();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);

    int state;
    int value_48;
    int value_4c;
    Sprite_00119F70 *sprite_50;
    Sprite_00119F70 *sprite_54;
    Sprite_00119F70 *sprite_58;
    Vector3 offset;
};

// Creates three sprites of group 0x12.
Object_0011A020::Object_0011A020(Node *owner, int id, unsigned int flags, int first, int second)
    : Node(owner, id, flags)
{
    value_48 = first;
    value_4c = second;
    state = 0;
    sprite_50 = (Sprite_00119F70 *)func_00025700(0x12, 1, 2, 0xa);
    sprite_54 = (Sprite_00119F70 *)func_00025700(0x12, 1, 2, 0xc);
    sprite_58 = (Sprite_00119F70 *)func_00025700(0x12, 1, 4, 2);
    offset.x = -32.0f;
    offset.y = 24.0f;
    offset.z = 1220.0f;
}
