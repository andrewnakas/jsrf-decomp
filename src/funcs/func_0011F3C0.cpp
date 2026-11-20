/* sym: ??0Object_0011F530@@QAE@PAUNode@@HI@Z = 0x0011F3C0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_0011F530@@UAE@XZ = 0x0011F530 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_0011F530@@UAEXXZ = 0x0011F540 */
/* sym: ?func_00011C80@Object_0011F530@@UAEXH@Z = 0x0011F7D0 */
/* sym: ?func_00011C90_4@Object_0011F530@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_2@Object_0011F530@@UAEXH@Z = 0x000B3DE0 */
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

struct Sprite_0011F3C0 {
    char unknown_00[0x24];
    unsigned int flags;
};

struct Object_00074E50 {
    char unknown_000[0x178];
    int value_178;

    int func_00074E50(int index);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
void *func_00025700(unsigned int index, int first, int second, int third);

// The class whose table is at 0x1D8F88: overrides slots 1, 3 of Node; slots 7, 9 hold folded thunks.
struct Object_0011F530 : Node {
    Object_0011F530(Node *owner, int id, unsigned int flags);
    virtual ~Object_0011F530();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);

    int unknown_44;
    int current;
    int shown;
    int value_50;
    int value_54;
    int value_58;
    float x;
    float y;
    float z;
    Sprite_0011F3C0 *sprite_68;
    Sprite_0011F3C0 *sprite_6c;
    Sprite_0011F3C0 *sprite_70;
    Sprite_0011F3C0 *sprite_74;
    Sprite_0011F3C0 *sprite_78;
    int value_7c;
    Sprite_0011F3C0 *sprite_80;
    Sprite_0011F3C0 *sprite_84;
    int value_88;
    float phase;
    float speed;
    float timer;
    int value_98;
    int value_9c;
};

Object_0011F530::Object_0011F530(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
{
    Object_00074E50 *menu = (Object_00074E50 *)data_0022FCE0->func_000128C0(0x128a);
    value_58 = menu->value_178;
    x = -32.0f;
    y = 24.0f;
    z = 1220.0f;
    value_98 = 0;
    value_9c = 0;
    value_50 = 1;
    current = menu->func_00074E50(5);
    shown = current;
    value_54 = current;
    sprite_6c = (Sprite_0011F3C0 *)func_00025700(0x12, 0, 2, 0x40);
    if (sprite_6c) {
        sprite_6c->flags &= ~1;
    }
    sprite_74 = (Sprite_0011F3C0 *)func_00025700(0x12, 0, 3, 2);
    sprite_78 = (Sprite_0011F3C0 *)func_00025700(0x12, 0, 3, 3);
    sprite_70 = sprite_78;
    value_7c = 0;
    sprite_80 = (Sprite_0011F3C0 *)func_00025700(0x12, 0, 2, 0x3f);
    if (sprite_80) {
        sprite_80->flags &= ~1;
        sprite_80->flags |= 1;
    }
    sprite_84 = (Sprite_0011F3C0 *)func_00025700(0x12, 0, 3, 0);
    value_88 = 0;
    sprite_68 = (Sprite_0011F3C0 *)func_00025700(0x12, 0, 2, 0x41);
    if (sprite_68) {
        sprite_68->flags &= ~1;
        sprite_68->flags |= 1;
        sprite_68->flags &= ~8;
    }
    phase = 0;
    speed = 1.0f;
    timer = 0.5f;
}
