/* sym: ??1Object_00050170@@UAE@XZ = 0x00050170 */
/* sym: ?func_00011C90@Object_00050170@@UAEXXZ = 0x00050330 */
/* sym: ?func_00011C80@Object_00050170@@UAEXH@Z = 0x00050180 */
struct Vector3 {
    float x;
    float y;
    float z;
};

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

// A camera node (table 0x1C43D8 repeats Node's slots 1 to 15; mask 7): eye, target, field of view and roll.
struct Object_00012170 : Node {
    Object_00012170(Node *owner, int id, unsigned int flags);
    virtual ~Object_00012170();

    Vector3 eye;
    char unknown_50[0xc];
    Vector3 target;
    char unknown_68[0xc];
    unsigned int fov;
    int unknown_78;
    int roll;
    int unknown_80;
    int left;
    int top;
    int width;
    int height;
    int unknown_94;
};

/* sym: ??0Object_00050170@@QAE@PAUNode@@HI@Z = 0x00055CA0 */
/* sym: ??0Object_00012170@@QAE@PAUNode@@HI@Z = 0x00012170 */
/* sym: ??1Object_00012170@@UAE@XZ = 0x000121D0 */

void *func_00025700(unsigned int index, int first, int second, int third);

struct Game {
    char unknown_0000[0x8838];
    int unknown_8838;
};

extern Game *data_0022FCE0;

// The class whose table is at 0x1CABD8: overrides slots 1 (50330), 3 (50180).
struct Object_00050170 : Object_00012170 {
    virtual ~Object_00050170();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);

    Object_00050170(Node *owner, int id, unsigned int flags);

    int unknown_98;
    void *unknown_9c;
    int unknown_a0;
    int unknown_a4;
};

Object_00050170::Object_00050170(Node *owner, int id, unsigned int flags) : Object_00012170(owner, id, flags)
{
    unknown_a4 = data_0022FCE0->unknown_8838;
    unknown_9c = func_00025700(0xb, 0, 5, 3);
    unknown_a0 = 0;
    unknown_98 = 0;
    left = 0;
    top = 0;
    width = 0x100;
    height = 0x100;
}
