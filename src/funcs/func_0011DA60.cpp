/* sym: ??0Object_0011DC20@@QAE@PAUNode@@HIHH@Z = 0x0011DA60 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_0011DC20@@UAE@XZ = 0x0011DC20 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_0011DC20@@UAEXXZ = 0x0011DC30 */
/* sym: ?func_00011C80@Object_0011DC20@@UAEXH@Z = 0x0011DD10 */
/* sym: ?func_00011C90_4@Object_0011DC20@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_2@Object_0011DC20@@UAEXH@Z = 0x000B3DE0 */
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

struct Sprite_0011DA60 {
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

// The class whose table is at 0x1D8CD0: overrides slots 1, 3 of Node; slots 7, 9 hold folded thunks.
struct Object_0011DC20 : Node {
    Object_0011DC20(Node *owner, int id, unsigned int flags, int kind, int mode);
    virtual ~Object_0011DC20();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);

    int unknown_44;
    int current;
    int shown;
    int mode;
    int kind;
    Sprite_0011DA60 *sprite_58;
    Sprite_0011DA60 *sprites[3];
    Sprite_0011DA60 *sprite_68;
    Sprite_0011DA60 *sprite_6c;
    int value_70;
    char unknown_74[0xc];
    Sprite_0011DA60 *sprite_80;
    Sprite_0011DA60 *sprite_84;
    int value_88;
    float x;
    float y;
    float z;
    int value_98;
    int value_9c;
};

Object_0011DC20::Object_0011DC20(Node *owner, int id, unsigned int flags, int kind, int mode)
    : Node(owner, id, flags)
{
    Object_00067380 *menu = (Object_00067380 *)data_0022FCE0->func_000128C0(0x12af);
    this->kind = kind;
    this->mode = mode;
    x = -32.0f;
    y = 24.0f;
    z = 1220.0f;
    value_98 = 0;
    value_9c = 0;
    current = menu->func_00067380(1);
    shown = current;
    if (!this->mode) {
        sprite_68 = (Sprite_0011DA60 *)func_00025700(10, 0, 1, 0x94);
        if (sprite_68) {
            sprite_68->flags &= ~1;
            sprite_68->flags |= 1;
        }
        sprite_6c = (Sprite_0011DA60 *)func_00025700(10, 0, 2, 0x26);
    } else {
        sprite_68 = (Sprite_0011DA60 *)func_00025700(10, 0, 1, 0x95);
        if (sprite_68) {
            sprite_68->flags &= ~1;
            sprite_68->flags |= 1;
        }
        sprite_6c = (Sprite_0011DA60 *)func_00025700(10, 0, 2, 0x27);
    }
    value_70 = 0;
    for (int i = 0; i < 3; i++) {
        sprites[i] = (Sprite_0011DA60 *)func_00025700(10, 0, 1, i + 0x97);
        if (sprites[i]) {
            sprites[i]->flags &= ~1;
            sprites[i]->flags |= 1;
        }
    }
    sprite_58 = (Sprite_0011DA60 *)func_00025700(10, 0, 1, this->kind + 0x91);
    if (sprite_58) {
        sprite_58->flags &= ~1;
        sprite_58->flags |= 1;
        sprite_58->flags &= ~8;
    }
    sprite_80 = (Sprite_0011DA60 *)func_00025700(10, 0, 1, 0x96);
    if (sprite_80) {
        sprite_80->flags &= ~1;
        sprite_80->flags |= 1;
    }
    sprite_84 = (Sprite_0011DA60 *)func_00025700(10, 0, 2, 0x15);
    value_88 = 0;
}
