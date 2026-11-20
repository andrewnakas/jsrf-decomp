/* sym: ??0Object_0011D420@@QAE@PAUNode@@HI@Z = 0x0011D230 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_0011D420@@UAE@XZ = 0x0011D420 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_0011D420@@UAEXXZ = 0x0011D430 */
/* sym: ?func_00011C80@Object_0011D420@@UAEXH@Z = 0x0011D740 */
/* sym: ?func_00011C90_4@Object_0011D420@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_2@Object_0011D420@@UAEXH@Z = 0x000B3DE0 */
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

struct Sprite_0011D230 {
    char unknown_00[0x24];
    unsigned int flags;
};

struct Object_00074E50 {
    int func_00074E50(int index);
};

struct Game {
    void *func_000128C0(int id);
    int func_000127E0(int index);
};

extern Game *data_0022FCE0;
void *func_00025700(unsigned int index, int first, int second, int third);

// The class whose table is at 0x1D8C90: overrides slots 1, 3 of Node; slots 7, 9 hold folded thunks.
struct Object_0011D420 : Node {
    Object_0011D420(Node *owner, int id, unsigned int flags);
    virtual ~Object_0011D420();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);

    int unknown_44;
    int current;
    int shown;
    Sprite_0011D230 *sprite_50;
    Sprite_0011D230 *sprites[2];
    char unknown_5c[0x24];
    float x;
    float y;
    float z;
    Sprite_0011D230 *sprite_8c;
    Sprite_0011D230 *sprite_90;
    int value_94;
    Sprite_0011D230 *sprite_98;
    float phase;
    float speed;
    float timer;
    int value_a8;
    int value_ac;
};

Object_0011D420::Object_0011D420(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
{
    Object_00074E50 *menu = (Object_00074E50 *)data_0022FCE0->func_000128C0(0x128a);
    for (int i = 0; i < 2; i++) {
        sprites[i] = 0;
    }
    x = -32.0f;
    y = 24.0f;
    z = 1220.0f;
    value_a8 = 0;
    value_ac = 0;
    current = menu->func_00074E50(3);
    shown = current;
    if (!data_0022FCE0->func_000127E0(0x1a9)) {
        sprites[0] = (Sprite_0011D230 *)func_00025700(0xf, 0, 1, 0x14);
        sprites[1] = (Sprite_0011D230 *)func_00025700(0xf, 0, 1, 0x15);
        sprite_50 = (Sprite_0011D230 *)func_00025700(0xf, 0, 1, 0x13);
        sprite_8c = (Sprite_0011D230 *)func_00025700(0xf, 0, 1, 0x12);
        sprite_90 = (Sprite_0011D230 *)func_00025700(0xa, 0, 2, 0x15);
        sprite_98 = (Sprite_0011D230 *)func_00025700(0xf, 0, 1, 0x16);
    } else {
        sprites[0] = (Sprite_0011D230 *)func_00025700(0x12, 0, 2, 0x50);
        sprites[1] = (Sprite_0011D230 *)func_00025700(0x12, 0, 2, 0x51);
        sprite_50 = (Sprite_0011D230 *)func_00025700(0x12, 0, 2, 0x4f);
        sprite_8c = (Sprite_0011D230 *)func_00025700(0x12, 0, 2, 0x4e);
        sprite_90 = (Sprite_0011D230 *)func_00025700(0x12, 0, 3, 5);
        sprite_98 = (Sprite_0011D230 *)func_00025700(0x12, 0, 2, 0x52);
    }
    if (sprites[1]) {
        sprites[1]->flags &= ~1;
    }
    if (sprites[0]) {
        sprites[0]->flags &= ~1;
    }
    if (sprite_50) {
        sprite_50->flags &= ~1;
        sprite_50->flags |= 1;
        sprite_50->flags &= ~8;
    }
    if (sprite_8c) {
        sprite_8c->flags &= ~1;
        sprite_8c->flags |= 1;
    }
    value_94 = 0;
    phase = 0;
    speed = 1.0f;
    timer = 0.5f;
}
