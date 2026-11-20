/* sym: ??0Object_001128B0@@QAE@PAUNode@@HI@Z = 0x00112680 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_001128B0@@UAE@XZ = 0x001128B0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90_2@Object_001128B0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_4@Object_001128B0@@UAEXXZ = 0x001128C0 */
/* sym: ?func_00011C80_2@Object_001128B0@@UAEXH@Z = 0x001129E0 */
/* sym: ?func_00011C90_6@Object_001128B0@@UAEXXZ = 0x000AECC0 */
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

struct Sprite_00112680 {
    char unknown_00[0x24];
    unsigned int flags;
};

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_00077B70 {
    int func_00077B70(int index);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
extern Vector3 data_00220A58;

void *func_00025700(unsigned int index, int first, int second, int third);

// The class whose table is at 0x1D2A00.
struct Object_001128B0 : Node {
    Object_001128B0(Node *owner, int id, unsigned int flags);
    virtual ~Object_001128B0();
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();

    Sprite_00112680 *sprite_44;
    Sprite_00112680 *sprite_48;
    Sprite_00112680 *sprite_4c;
    Sprite_00112680 *sprite_50;
    Sprite_00112680 *sprite_54;
    Sprite_00112680 *sprite_58;
    Sprite_00112680 *sprite_5c;
    Sprite_00112680 *sprite_60;
    Sprite_00112680 *sprite_64;
    Sprite_00112680 *sprite_68;
    Sprite_00112680 *sprite_6c;
    Sprite_00112680 *sprite_70;
    Sprite_00112680 *first;
    float firstFrame;
    Sprite_00112680 *sprite_7c;
    Sprite_00112680 *sprite_80;
    Sprite_00112680 *sprite_84;
    Sprite_00112680 *second;
    float secondFrame;
    Sprite_00112680 *sprite_90;
    Sprite_00112680 *third;
    float thirdFrame;
    Vector3 position;
    char unknown_0a8[0x100];
    int value_1a8;
    int value_1ac;
    int value;
    float timer;
};

// Unless menu object 0x1167 is missing (then the node unlinks itself), creates the sprites and three animations
// and takes value from the menu's func_00077B70(0).
Object_001128B0::Object_001128B0(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
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
    sprite_5c = 0;
    sprite_58 = 0;
    sprite_60 = 0;
    sprite_64 = 0;
    sprite_70 = 0;
    sprite_68 = 0;
    sprite_6c = 0;
    position.x = data_00220A58.x;
    position.y = data_00220A58.y;
    position.z = data_00220A58.z;
    value_1a8 = 0;
    value_1ac = 0;
    value = menu->func_00077B70(0);
    timer = 0.0f;
    sprite_44 = (Sprite_00112680 *)func_00025700(10, 0, 1, 0x3);
    sprite_48 = (Sprite_00112680 *)func_00025700(10, 0, 1, 0x4);
    sprite_70 = (Sprite_00112680 *)func_00025700(10, 0, 1, 0x6b);
    first = (Sprite_00112680 *)func_00025700(10, 0, 2, 0x12);
    firstFrame = 0.0f;
    sprite_7c = (Sprite_00112680 *)func_00025700(10, 0, 1, 0x80);
    sprite_4c = (Sprite_00112680 *)func_00025700(10, 0, 1, 0x5);
    sprite_50 = (Sprite_00112680 *)func_00025700(10, 0, 1, 0x6);
    sprite_58 = (Sprite_00112680 *)func_00025700(10, 0, 1, 0x8);
    sprite_5c = (Sprite_00112680 *)func_00025700(10, 0, 1, 0x9);
    sprite_68 = (Sprite_00112680 *)func_00025700(10, 0, 1, 0x9c);
    if (sprite_68) {
        sprite_68->flags &= ~1;
        sprite_68->flags |= 1;
    }
    sprite_6c = (Sprite_00112680 *)func_00025700(10, 0, 1, 0x9d);
    sprite_80 = (Sprite_00112680 *)func_00025700(10, 0, 1, 0x101);
    sprite_84 = (Sprite_00112680 *)func_00025700(10, 0, 1, 0x102);
    second = (Sprite_00112680 *)func_00025700(10, 0, 2, 0x11);
    secondFrame = 0.0f;
    sprite_90 = (Sprite_00112680 *)func_00025700(10, 0, 1, 0x100);
    third = (Sprite_00112680 *)func_00025700(10, 0, 2, 0x2f);
    thirdFrame = 0.0f;
}
