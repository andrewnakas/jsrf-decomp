/* sym: ??0Object_000FBFD0@@QAE@PAUNode@@HIHPAHIH@Z = 0x000FBFD0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ??1Object_000FBFD0@@UAE@XZ = 0x000FC1A0 */
/* sym: ?func_00011C90@Object_000FBFD0@@UAEXXZ = 0x000FC250 */
/* sym: ?func_00011C80@Object_000FBFD0@@UAEXH@Z = 0x000FC370 */
/* sym: ?func_00011C90_2@Object_000FBFD0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_1@Object_000FBFD0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_4@Object_000FBFD0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_2@Object_000FBFD0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_6@Object_000FBFD0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_3@Object_000FBFD0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_8@Object_000FBFD0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_4@Object_000FBFD0@@UAEXH@Z = 0x000B3DE0 */
struct Node {
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

    Node(Node *parent, int id, unsigned int mask);
    Node *func_00011BD0();

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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The objects with ids 0x115e to 0x1162 (table 0x1D2020).
struct Object_00107FE0 {
    int func_00107AB0();
};

// The parent's ids at 0xb0 and 0xb8.
struct Parent_000FBFD0 : Node {
    char unknown_040[0x70];
    int id_b0;
    char unknown_0b4[4];
    int id_b8;
};

struct Sprite_000FC630;

extern Vector3 data_00220A58;

// The class whose table is at 0x1D1B68 (destructor func_000FC1A0); its constructor runs entry `mode` (at 0x58) of the
// member-function table at 0x21FDA8 on itself.
struct Object_000FBFD0 : Node {
    Object_000FBFD0(Node *parent, int id, unsigned int mask, int kind, int *result, unsigned int flags, int value);
    virtual ~Object_000FBFD0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C80_4(int argument);

    int unknown_040;
    unsigned int bits;
    Vector3 position;
    int kind;
    int mode;
    unsigned int flags_5c;
    Sprite_000FC630 *sprite_60;
    Sprite_000FC630 *sprite_64;
    Sprite_000FC630 *sprite_68;
    Sprite_000FC630 *sprite_6c;
    char unknown_070[4];
    float alpha;
    char unknown_078[4];
    Sprite_000FC630 *sprite_7c;
    Sprite_000FC630 *sprite_80;
    Sprite_000FC630 *sprite_84;
    Sprite_000FC630 *sprite_88;
    int value_8c;
    float fade;
    int value_94;
    int value_98;
    int *result;
    int value_a0;
    int ownerValue;
    float scale;
};

extern void (Object_000FBFD0::*data_0021FDA8[])();

// Keeps the kind, the flags and the value, clears the sprites and the result, starts at data_00220A58 and picks the
// mode by kind (2 for 0-7, 10-14 and 44, 0 for 8, 9 and 39-43, 1 for 15-37) whose handler of data_0021FDA8 loads its
// sprites. With flag 0x10000000 the value of its 0x115e-range owner (func_00107AB0) goes to 0xa4: the parent itself
// (flag 0x8000000) or the object whose id the parent keeps at 0xb8 (0x4000000) or 0xb0 (0x2000000). Scale 1.
Object_000FBFD0::Object_000FBFD0(Node *parent, int id, unsigned int mask, int kind, int *result, unsigned int flags,
                                 int value)
    : Node(parent, id, mask)
{
    this->kind = kind;
    flags_5c = flags;
    value_a0 = value;
    sprite_60 = 0;
    sprite_64 = 0;
    sprite_68 = 0;
    sprite_6c = 0;
    sprite_7c = 0;
    sprite_84 = 0;
    sprite_88 = 0;
    mode = 0;
    bits = 0;
    this->result = result;
    if (result) {
        *result = 0;
    }
    position.x = data_00220A58.x;
    position.y = data_00220A58.y;
    position.z = data_00220A58.z;
    value_94 = 0;
    value_98 = 0;
    alpha = 0.0f;
    fade = 0.0f;
    value_8c = 0;
    switch (this->kind) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 44:
        mode = 2;
        break;
    case 8:
    case 9:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
        mode = 0;
        break;
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
        mode = 1;
        break;
    }
    (this->*data_0021FDA8[mode])();
    sprite_80 = sprite_84;
    ownerValue = 0;
    if (flags_5c & 0x10000000) {
        Object_00107FE0 *owner;
        if (flags_5c & 0x8000000) {
            owner = (Object_00107FE0 *)func_00011BD0();
        } else if (flags_5c & 0x4000000) {
            owner = (Object_00107FE0 *)data_0022FCE0->func_000128C0(((Parent_000FBFD0 *)func_00011BD0())->id_b8);
        } else if (flags_5c & 0x2000000) {
            owner = (Object_00107FE0 *)data_0022FCE0->func_000128C0(((Parent_000FBFD0 *)func_00011BD0())->id_b0);
        } else {
            owner = 0;
        }
        if (owner) {
            ownerValue = owner->func_00107AB0();
        }
    }
    scale = 1.0f;
}
