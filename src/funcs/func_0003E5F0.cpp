/* sym: ??0Object_0003E420@@QAE@PAUNode@@HI@Z = 0x0003E5F0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_0003E420@@UAE@XZ = 0x0003E420 */
/* sym: ?func_00011C80@Object_0003E420@@UAEXH@Z = 0x0003E660 */
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

struct Vector3 {
    float x;
    float y;
    float z;
};

// The class whose table is at 0x1CA4C8: a light with a colour (0xFFFFFF) and a direction (constructor 0x3E5F0).
struct Object_0003E420 : Node {
    Object_0003E420(Node *owner, int id, unsigned int flags);
    virtual ~Object_0003E420();
    virtual void func_00011C80(int argument);

    int colour;
    char unknown_48[4];
    Vector3 direction;
    Vector3 viewDirection;
};

Object_0003E420::Object_0003E420(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
{
    direction.x = -0.4163f;
    direction.y = -0.7199f;
    direction.z = -0.6334f;
    colour = 0xffffff;
}
