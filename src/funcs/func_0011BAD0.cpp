/* sym: ??0Object_0011BCA0@@QAE@PAUNode@@HI@Z = 0x0011BAD0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_0011BCA0@@UAE@XZ = 0x0011BCA0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_0011BCA0@@UAEXXZ = 0x0011BCB0 */
/* sym: ?func_00011C80@Object_0011BCA0@@UAEXH@Z = 0x0011C070 */
/* sym: ?func_00011C90_4@Object_0011BCA0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_2@Object_0011BCA0@@UAEXH@Z = 0x000B3DE0 */
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

struct Sprite_0011BAD0 {
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

// The class whose table is at 0x1D8638: overrides slots 1, 3 of Node; slots 7, 9 hold folded thunks.
struct Object_0011BCA0 : Node {
    Object_0011BCA0(Node *owner, int id, unsigned int flags);
    virtual ~Object_0011BCA0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);

    int unknown_44;
    int current;
    int shown;
    Sprite_0011BAD0 *sprites[6];
    char unknown_68[0x18];
    float x;
    float y;
    float z;
    Sprite_0011BAD0 *sprite_8c;
    Sprite_0011BAD0 *sprite_90;
    int value_94;
    float phase;
    float speed;
    float timer;
    int value_a4;
    int value_a8;
};

Object_0011BCA0::Object_0011BCA0(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
{
    Object_00074E50 *menu = (Object_00074E50 *)data_0022FCE0->func_000128C0(0x128a);
    int i;
    for (i = 0; i < 6; i++) {
        sprites[i] = 0;
    }
    x = -32.0f;
    y = 24.0f;
    z = 1220.0f;
    value_a4 = 0;
    value_a8 = 0;
    current = menu->func_00074E50(0);
    shown = current;
    if (!data_0022FCE0->func_000127E0(0x1a9)) {
        for (i = 0; i < 6; i++) {
            sprites[i] = (Sprite_0011BAD0 *)func_00025700(0xf, 0, 1, i + 8);
        }
        sprite_8c = (Sprite_0011BAD0 *)func_00025700(0xf, 0, 1, 7);
        if (sprite_8c) {
            sprite_8c->flags &= ~1;
            sprite_8c->flags |= 1;
        }
        sprite_90 = (Sprite_0011BAD0 *)func_00025700(0xf, 0, 2, 0);
    } else {
        for (i = 0; i < 6; i++) {
            sprites[i] = (Sprite_0011BAD0 *)func_00025700(0x12, 0, 2, i + 0x44);
        }
        sprite_8c = (Sprite_0011BAD0 *)func_00025700(0x12, 0, 2, 0x43);
        if (sprite_8c) {
            sprite_8c->flags &= ~1;
            sprite_8c->flags |= 1;
        }
        sprite_90 = (Sprite_0011BAD0 *)func_00025700(0x12, 0, 3, 4);
    }
    for (i = 0; i < 6; i++) {
        if (sprites[i]) {
            sprites[i]->flags &= ~1;
        }
    }
    value_94 = 0;
    phase = 0;
    speed = 1.0f;
    timer = 0.5f;
}
