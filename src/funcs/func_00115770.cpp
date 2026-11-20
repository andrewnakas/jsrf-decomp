/* sym: ??0Object_00115900@@QAE@PAUNode@@HI@Z = 0x00115770 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_00115900@@UAE@XZ = 0x00115900 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_00115900@@UAEXXZ = 0x00113CD0 */
/* sym: ?func_00011C90_2@Object_00115900@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_4@Object_00115900@@UAEXXZ = 0x00115910 */
/* sym: ?func_00011C80_2@Object_00115900@@UAEXH@Z = 0x00115A40 */
/* sym: ?func_00011C90_6@Object_00115900@@UAEXXZ = 0x000AECC0 */
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

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// A sprite func_00025700 returns: flags at 0x24.
struct Sprite_00113040 {
    char unknown_00[0x24];
    unsigned int flags;
};

// Menu object 0x1167.
struct Object_00077BF0 {
    int func_00077B90(int list, int key);
    int func_00077BF0(int list, int index);
    int func_00077C10(int list, int index);
};

extern Vector3 data_00220A58;

void *func_00025700(unsigned int index, int first, int second, int third);

// The class whose table is at 0x1D2BB0: overrides slots 1, 7, 9 of Node; slots 4, 10 hold folded thunks.
struct Object_00115900 : Node {
    Object_00115900(Node *owner, int id, unsigned int flags);
    virtual ~Object_00115900();
    virtual void func_00011C90();
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();

    char unknown_044[8];
    Sprite_00113040 *sprite_4c;
    Sprite_00113040 *sprite_50;
    Sprite_00113040 *items[24];
    Vector3 position;
    char unknown_0c0[8];
    int value_c8;
    int value_cc;
    Sprite_00113040 *sprite_d0;
    Sprite_00113040 *first;
    float firstFrame;
    Sprite_00113040 *sprite_dc;
    int value_e0;
    float scale;
};

// Unless menu object 0x1167 is missing (then the node unlinks itself), creates the sprites: 4 and 0xd5, one for each
// of the 24 entries of list 1 the menu has (func_00077B90 or func_00077C10; 0xd6 plus its func_00077BF0 index, flag
// 0x24 bit 0 set), 0x6b, the animation 0x12 (list 2) and 0x80.
Object_00115900::Object_00115900(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
{
    Object_00077BF0 *menu = (Object_00077BF0 *)data_0022FCE0->func_000128C0(0x1167);
    if (menu == 0) {
        func_00011BE0(this);
        func_00011C20(child);
        return;
    }
    position.x = data_00220A58.x;
    position.y = data_00220A58.y;
    position.z = data_00220A58.z;
    value_c8 = 0;
    value_cc = 0;
    sprite_4c = (Sprite_00113040 *)func_00025700(10, 0, 1, 4);
    sprite_50 = (Sprite_00113040 *)func_00025700(10, 0, 1, 0xd5);
    for (int i = 0; i < 24; i++) {
        if (menu->func_00077B90(1, i) || menu->func_00077C10(1, i)) {
            items[i] = (Sprite_00113040 *)func_00025700(10, 0, 1, menu->func_00077BF0(1, i) + 0xd6);
            if (items[i]) {
                items[i]->flags &= ~1;
                items[i]->flags |= 1;
            }
        } else {
            items[i] = 0;
        }
    }
    sprite_d0 = (Sprite_00113040 *)func_00025700(10, 0, 1, 0x6b);
    first = (Sprite_00113040 *)func_00025700(10, 0, 2, 0x12);
    firstFrame = 0.0f;
    sprite_dc = (Sprite_00113040 *)func_00025700(10, 0, 1, 0x80);
    value_e0 = 0;
    scale = 1.0f;
}
