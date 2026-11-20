/* sym: ??0Object_0011E2A0@@QAE@PAUNode@@HIH@Z = 0x0011E100 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_0011E2A0@@UAE@XZ = 0x0011E2A0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_0011E2A0@@UAEXXZ = 0x0011E2B0 */
/* sym: ?func_00011C80@Object_0011E2A0@@UAEXH@Z = 0x0011E420 */
/* sym: ?func_00011C90_4@Object_0011E2A0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_2@Object_0011E2A0@@UAEXH@Z = 0x000B3DE0 */
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

struct Sprite_0011E100 {
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

// The class whose table is at 0x1D8E88: overrides slots 1, 3 of Node; slots 7, 9 hold folded thunks.
struct Object_0011E2A0 : Node {
    Object_0011E2A0(Node *owner, int id, unsigned int flags, int kind);
    virtual ~Object_0011E2A0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);

    int kind;
    int unknown_48;
    int current;
    int shown;
    Sprite_0011E100 *sprite_54;
    Sprite_0011E100 *sprite_58;
    Sprite_0011E100 *sprite_5c;
    Sprite_0011E100 *sprite_60;
    char unknown_64[0x24];
    float x;
    float y;
    float z;
    Sprite_0011E100 *sprite_94;
    Sprite_0011E100 *sprite_98;
    int value_9c;
    float phase;
    float speed;
    float timer;
    int value_ac;
    int value_b0;
};

Object_0011E2A0::Object_0011E2A0(Node *owner, int id, unsigned int flags, int kind) : Node(owner, id, flags)
{
    Object_00067380 *menu = (Object_00067380 *)data_0022FCE0->func_000128C0(0x12af);
    this->kind = kind;
    x = -32.0f;
    y = 24.0f;
    z = 1220.0f;
    value_ac = 0;
    value_b0 = 0;
    current = menu->func_00067380(0);
    shown = current;
    sprite_58 = (Sprite_0011E100 *)func_00025700(10, 0, 1, 0x94);
    if (sprite_58) {
        sprite_58->flags &= ~1;
        sprite_58->flags |= 1;
    }
    sprite_5c = (Sprite_0011E100 *)func_00025700(10, 0, 1, 0x95);
    if (sprite_5c) {
        sprite_5c->flags &= ~1;
        sprite_5c->flags |= 1;
    }
    sprite_60 = (Sprite_0011E100 *)func_00025700(10, 0, 1, 0x93);
    if (sprite_60) {
        sprite_60->flags &= ~1;
        sprite_60->flags |= 1;
    }
    sprite_54 = (Sprite_0011E100 *)func_00025700(10, 0, 1, this->kind + 0x91);
    if (sprite_54) {
        sprite_54->flags &= ~1;
        sprite_54->flags |= 1;
        sprite_54->flags &= ~8;
    }
    sprite_94 = (Sprite_0011E100 *)func_00025700(10, 0, 1, 0x90);
    if (sprite_94) {
        sprite_94->flags &= ~1;
        sprite_94->flags |= 1;
    }
    sprite_98 = (Sprite_0011E100 *)func_00025700(10, 0, 2, 0x15);
    value_9c = 0;
    phase = 0;
    speed = 1.0f;
    timer = 0.5f;
}
