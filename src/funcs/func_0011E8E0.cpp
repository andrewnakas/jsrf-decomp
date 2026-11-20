/* sym: ??0Object_0011E9D0@@QAE@PAUNode@@HI@Z = 0x0011E8E0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ??1Object_0011E9D0@@UAE@XZ = 0x0011E9D0 */
/* sym: ?func_00011C90@Object_0011E9D0@@UAEXXZ = 0x0011E9E0 */
/* sym: ?func_00011C80@Object_0011E9D0@@UAEXH@Z = 0x0011EAF0 */
/* sym: ?func_00011C90_4@Object_0011E9D0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_2@Object_0011E9D0@@UAEXH@Z = 0x000B3DE0 */
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

struct Sprite_0011E8E0 {
    char unknown_00[0x24];
    unsigned int flags;
};

struct Object_00067380 {
    int func_00067380(int index);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
void *func_00025700(unsigned int index, int first, int second, int third);

// The class whose table is at 0x1D8EC8: overrides slots 1, 3 of Node; slots 7, 9 hold folded thunks.
struct Object_0011E9D0 : Node {
    Object_0011E9D0(Node *owner, int id, unsigned int flags);
    virtual ~Object_0011E9D0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);

    int unknown_44;
    int current;
    int shown;
    Sprite_0011E8E0 *first;
    Sprite_0011E8E0 *second;
    char unknown_58[8];
    float x;
    float y;
    float z;
    unsigned int state;
    int value_70;
    float phase;
    float speed;
    float timer;
    int value_80;
};

Object_0011E9D0::Object_0011E9D0(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
{
    Object_00067380 *menu = (Object_00067380 *)data_0022FCE0->func_000128C0(0x12af);
    x = -32.0f;
    y = 24.0f;
    z = 1220.0f;
    state = 0;
    value_70 = 0;
    value_80 = -1;
    current = menu->func_00067380(2);
    shown = current;
    first = (Sprite_0011E8E0 *)func_00025700(10, 0, 1, 0x9a);
    if (first) {
        first->flags &= ~1;
    }
    second = (Sprite_0011E8E0 *)func_00025700(10, 0, 1, 0x9b);
    if (second) {
        second->flags &= ~1;
    }
    phase = 0;
    speed = 1.0f;
    timer = 0.5f;
}
