/* sym: ??0Object_00104EE0@@QAE@PAUNode@@HI@Z = 0x00104E00 */
/* sym: ??1Object_00104EE0@@UAE@XZ = 0x00104EE0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ?func_00011C80@Object_00104EE0@@UAEXH@Z = 0x00105070 */
/* sym: ?func_00011C90_2@Object_00104EE0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_4@Object_00104EE0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_6@Object_00104EE0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_8@Object_00104EE0@@UAEXXZ = 0x000AECC0 */
extern "C" void *memset(void *destination, int value, unsigned int size);

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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;

    Node *func_00011BD0();
};


// A sprite from func_00025700: a value at 0x10 and flags at 0x24.
struct Sprite_00104E00 {
    char unknown_00[0x10];
    int value_10;
    char unknown_14[0x10];
    unsigned int flags;
};

void *func_00025700(unsigned int index, int first, int second, int third);

// A direct child of Node (table 0x1D1F58, destructor func_00104EE0).
struct Object_00104EE0 : Node {
    Object_00104EE0(Node *owner, int id, unsigned int flags);
    virtual ~Object_00104EE0();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();

    int unknown_040;
    int value_44;
    int value_48;
    Sprite_00104E00 *sprites[3];
    void *sprite_58;
    float x;
    float y;
    float z;
    int value_68;
    int value_6c;
    int value_70;
};

// Runs func_00011BD0, clears its fields, puts the point at (-32, 24, 1220); the three sprites 0xfb to 0xfd of set 0xa
// (func_00025700) with bit 0 of their flags cleared and 5 at 0x10, and sprite 0x2c of set 0xa at 0x58.
Object_00104EE0::Object_00104EE0(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
{
    func_00011BD0();
    memset(sprites, 0, sizeof sprites);
    sprite_58 = 0;
    value_68 = 0;
    value_6c = 0;
    value_70 = 0;
    x = -32.0f;
    y = 24.0f;
    z = 1220.0f;
    for (int i = 0; i < 3; i++) {
        sprites[i] = (Sprite_00104E00 *)func_00025700(0xa, 0, 1, i + 0xfb);
        if (sprites[i]) {
            sprites[i]->flags &= ~1;
            sprites[i]->value_10 = 5;
        }
    }
    sprite_58 = func_00025700(0xa, 0, 2, 0x2c);
    value_44 = 0;
    value_48 = 0;
}
