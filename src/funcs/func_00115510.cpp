/* sym: ??0Object_00114FD0@@QAE@PAUNode@@HIHH@Z = 0x00115510 */
/* sym: ??0Object_00012170@@QAE@PAUNode@@HI@Z = 0x00012170 */
/* sym: ??1Object_00114FD0@@UAE@XZ = 0x00114FD0 */
/* sym: ??1Object_00012170@@UAE@XZ = 0x000121D0 */
/* sym: ??0Object_000FBFD0@@QAE@PAUNode@@HIHPAHIH@Z = 0x000FBFD0 */
/* sym: ?func_00011C90_2@Object_00114FD0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_4@Object_00114FD0@@UAEXXZ = 0x00114FE0 */
/* sym: ?func_00011C80_2@Object_00114FD0@@UAEXH@Z = 0x00115030 */
/* sym: ?func_00011C90_6@Object_00114FD0@@UAEXXZ = 0x000AECC0 */
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
    char unknown_34[0x60];
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// A node with no virtual functions of its own (table 0x1C43D8). Its destructor (0x121D0) is what this
// constructor's unwind code calls.
struct Object_00012170 : Node {
    Object_00012170(Node *owner, int id, unsigned int flags);
    virtual ~Object_00012170();

    int unknown_94;
};

struct Sprite_00115510 {
    char unknown_00[0x24];
    unsigned int flags;
};

struct Vector3 {
    float x;
    float y;
    float z;
};

// The node 0xFBFD0 builds (table 0x1D1B68); 0xAC bytes.
struct Object_000FBFD0 : Node {
    Object_000FBFD0(Node *owner, int id, unsigned int flags, int value, int *result, unsigned int color, int mode);

    char unknown_94[0x18];
};

extern Vector3 data_00220A58;

void *func_00025700(unsigned int index, int first, int second, int third);

// The class whose table is at 0x1D2B68, built on Object_00012170.
struct Object_00114FD0 : Object_00012170 {
    Object_00114FD0(Node *owner, int id, unsigned int flags, int first, int second);
    virtual ~Object_00114FD0();
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();

    Sprite_00115510 *sprites_98[4];
    Sprite_00115510 *digits[5];
    Sprite_00115510 *sprite_bc;
    Sprite_00115510 *sprite_c0;
    Sprite_00115510 *sprite_c4;
    Sprite_00115510 *animation;
    float frame;
    Sprite_00115510 *sprite_d0;
    int value_d4;
    float value_d8;
    float value_dc;
    char unknown_0e0[0x4];
    int value_e4;
    int value_e8;
    Vector3 position;
    int value_f8;
    int value_fc;
};

// Unless menu object 0x1167 is missing (then the node unlinks itself), creates the sprites and a child node
// (0xFBFD0) of this one.
Object_00114FD0::Object_00114FD0(Node *owner, int id, unsigned int flags, int first, int second)
    : Object_00012170(owner, id, flags)
{
    void *menu = data_0022FCE0->func_000128C0(0x1167);
    if (menu == 0) {
        func_00011BE0(this);
        func_00011C20(child);
        return;
    }
    value_e4 = first;
    value_e8 = second;
    position.x = data_00220A58.x;
    position.y = data_00220A58.y;
    position.z = data_00220A58.z;
    value_f8 = 0;
    value_fc = 0;
    sprites_98[0] = (Sprite_00115510 *)func_00025700(10, 0, 1, 4);
    sprites_98[1] = (Sprite_00115510 *)func_00025700(10, 0, 1, 0x9f);
    sprites_98[2] = (Sprite_00115510 *)func_00025700(10, 0, 1, 0xa0);
    sprites_98[3] = (Sprite_00115510 *)func_00025700(10, 0, 1, 0xa1);
    for (int i = 0; i < 5; i++) {
        digits[i] = (Sprite_00115510 *)func_00025700(10, 0, 1, 0xa2 + i);
    }
    sprite_bc = (Sprite_00115510 *)func_00025700(10, 0, 1, 0x9e);
    if (sprite_bc) {
        sprite_bc->flags &= ~1;
        sprite_bc->flags |= 1;
    }
    sprite_c0 = (Sprite_00115510 *)func_00025700(10, 0, 1, 0xff);
    if (sprite_c0) {
        sprite_c0->flags &= ~1;
        sprite_c0->flags |= 1;
    }
    sprite_c4 = (Sprite_00115510 *)func_00025700(10, 0, 1, 0x6b);
    animation = (Sprite_00115510 *)func_00025700(10, 0, 2, 0x12);
    frame = 0.0f;
    sprite_d0 = (Sprite_00115510 *)func_00025700(10, 0, 1, 0x80);
    value_d4 = 0;
    value_d8 = 1.0f;
    value_dc = 0.5f;
    new Object_000FBFD0(this, -1, 0x100, value_e4 + 0xf, 0, 0x80000000, -1);
}
