/* sym: ??0Object_00113280@@QAE@PAUNode@@HI@Z = 0x00113040 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_00113280@@UAE@XZ = 0x00113280 */
/* sym: ??0Object_000F7C50@@QAE@PAUNode@@HIHHHHPAM11PAXHI@Z = 0x000F7C50 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90_2@Object_00113280@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_4@Object_00113280@@UAEXXZ = 0x00113290 */
/* sym: ?func_00011C80_2@Object_00113280@@UAEXH@Z = 0x001133A0 */
/* sym: ?func_00011C90_6@Object_00113280@@UAEXXZ = 0x000AECC0 */
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
    char unknown_34[0x10];
};

struct Sprite_00113040 {
    char unknown_00[0x24];
    unsigned int flags;
};

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_00077B70 {
    char unknown_000[0x1c4];
    int *kind;

    int func_00077B70(int index);
};

struct Object_00043700 {
    int func_00043700();
};

// The node 0xF7C50 builds (table 0x1D0770); 0xCC bytes.
struct Object_000F7C50 : Node {
    Object_000F7C50(Node *owner, int id, unsigned int flags, int first, int second, int third, int fourth,
                    float *position, float *rotation, float *scale, void *block, int value, unsigned int color);

    char unknown_44[0x88];
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
extern Vector3 data_00220A58;
extern Object_00043700 data_001FC724;

void *func_00025700(unsigned int index, int first, int second, int third);

// The class whose table is at 0x1D2AA8.
struct Object_00113280 : Node {
    Object_00113280(Node *owner, int id, unsigned int flags);
    virtual ~Object_00113280();
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();

    Sprite_00113040 *sprite_44;
    Sprite_00113040 *sprite_48;
    Sprite_00113040 *sprite_4c;
    Sprite_00113040 *sprite_50;
    Sprite_00113040 *sprite_54;
    Sprite_00113040 *sprite_58;
    Sprite_00113040 *sprite_5c;
    Sprite_00113040 *first;
    float firstFrame;
    Sprite_00113040 *sprite_68;
    Sprite_00113040 *sprite_6c;
    Sprite_00113040 *third;
    Sprite_00113040 *sprite_74;
    Sprite_00113040 *sprite_78;
    Sprite_00113040 *second;
    float secondFrame;
    Vector3 position;
    char unknown_090[0x100];
    int value_190;
    int value_194;
    int value;
    float timer;
};

// Unless menu object 0x1167 is missing (then the node unlinks itself), creates the sprites and animations; when
// the menu has a kind, also a child node (0xF7C50) with colour 0 or 0x80000000 by data_001FC724's func_00043700,
// and two more sprites for kinds 4 and 12.
Object_00113280::Object_00113280(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
{
    Object_00077B70 *menu = (Object_00077B70 *)data_0022FCE0->func_000128C0(0x1167);
    if (menu == 0) {
        func_00011BE0(this);
        func_00011C20(child);
        return;
    }
    sprite_44 = 0;
    sprite_48 = 0;
    sprite_4c = 0;
    sprite_50 = 0;
    sprite_54 = 0;
    sprite_58 = 0;
    sprite_5c = 0;
    sprite_6c = 0;
    third = 0;
    sprite_74 = 0;
    position.x = data_00220A58.x;
    position.y = data_00220A58.y;
    position.z = data_00220A58.z;
    value_190 = 0;
    value_194 = 0;
    value = menu->func_00077B70(0);
    timer = 0.0f;
    sprite_44 = (Sprite_00113040 *)func_00025700(10, 0, 1, 3);
    sprite_48 = (Sprite_00113040 *)func_00025700(10, 0, 1, 4);
    sprite_4c = (Sprite_00113040 *)func_00025700(10, 0, 1, 5);
    sprite_50 = (Sprite_00113040 *)func_00025700(10, 0, 1, 7);
    sprite_5c = (Sprite_00113040 *)func_00025700(10, 0, 1, 0x6b);
    first = (Sprite_00113040 *)func_00025700(10, 0, 2, 0x12);
    firstFrame = 0.0f;
    sprite_68 = (Sprite_00113040 *)func_00025700(10, 0, 1, 0x80);
    if (menu->kind) {
        if (data_001FC724.func_00043700() == 0) {
            new Object_000F7C50(this, -1, 0x100, 0, -1, *menu->kind + 0xf, -1, 0, 0, 0, 0, 0, 0);
        } else {
            new Object_000F7C50(this, -1, 0x100, 0, -1, *menu->kind + 0xf, -1, 0, 0, 0, 0, 0, 0x80000000);
        }
        if (*menu->kind == 4 || *menu->kind == 0xc) {
            sprite_6c = (Sprite_00113040 *)func_00025700(0xb, 0, 1, 0x10);
            third = (Sprite_00113040 *)func_00025700(0xb, 0, 4, 7);
        }
    }
    sprite_78 = (Sprite_00113040 *)func_00025700(10, 0, 1, 0x100);
    second = (Sprite_00113040 *)func_00025700(10, 0, 2, 0x2f);
    secondFrame = 0.0f;
}
