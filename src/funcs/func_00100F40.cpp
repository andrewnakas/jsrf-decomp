/* sym: ??0Object_00101180@@QAE@PAUNode@@HIHHHH@Z = 0x00100F40 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_00101180@@UAE@XZ = 0x00101100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_00101180@@UAEXXZ = 0x00101180 */
/* sym: ?func_00011C90_1@Object_00101180@@UAEXXZ = 0x00101190 */
/* sym: ?func_00011C80@Object_00101180@@UAEXH@Z = 0x001011A0 */
extern "C" void *memset(void *destination, int value, unsigned int size);

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

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
};

// The objects with ids 0x115e to 0x1162.
struct Object_00107FE0 {
    int func_00107AB0();
};

struct Frame_00100F40 {
    char unknown_00[0x60];
    float value;
};

// What func_00025700 gives for (0xb, 0, 1, n).
struct Sprite_00100F40 {
    char unknown_00[8];
    Frame_00100F40 *frame;
    char unknown_0c[0x18];
    unsigned int flags;
};

void *func_00025700(unsigned int index, int first, int second, int third);

// The child of Node whose table is at 0x1D1D48 (destructor func_00101100); data_0021FF98 holds the handlers of its
// states.
struct Object_00101180 : Node {
    Object_00101180(Node *parent, int id, unsigned int mask, int ownerId, int kind, int first, int second);
    virtual ~Object_00101180();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);

    char unknown_040[4];
    int state;
    int unknown_048;
    int unknown_04c;
    int unknown_050;
    int unknown_054;
    Sprite_00100F40 *sprite;
    int unknown_05c;
    int unknown_060;
    Sprite_00100F40 *secondSprite;
    int unknown_068;
    int unknown_06c;
    char unknown_070[0x10];
    int second;
    int value_84;
    int unknown_088;
    int unknown_08c;
    int unknown_090;
    char unknown_094[0xc];
    float unknown_0a0[3];
    float scale[3];
    char unknown_0b8[0x64];
    float value_11c;
    float value_120;
    char unknown_124[8];
    int unknown_12c;
    int value_130;
    int ownerId;
    char unknown_138[0x54];
    int unknown_18c[6];
};

extern void (Object_00101180::*data_0021FF98[])();

// Keeps the owner's id (and its func_00107AB0 value at 0x130), the kind (its state, whose handler of data_0021FF98
// runs at once) and `second`, and loads the sprites of `first` (func_00025700 (0xb, 0, 1, n): 1, 3, 0xb, or 0xc
// and 0xd for 4, else 0); the first sprite's frame gives the value at 0x11c.
Object_00101180::Object_00101180(Node *parent, int id, unsigned int mask, int ownerId, int kind, int first,
                                 int second)
    : Node(parent, id, mask)
{
    memset(unknown_18c, 0, sizeof(unknown_18c));
    sprite = 0;
    unknown_05c = 0;
    unknown_060 = 0;
    secondSprite = 0;
    unknown_068 = 0;
    unknown_06c = 0;
    unknown_088 = 0;
    unknown_08c = 0;
    unknown_090 = 0;
    unknown_054 = 1;
    this->ownerId = ownerId;
    state = kind;
    this->second = second;
    value_130 = 0;
    Object_00107FE0 *owner = (Object_00107FE0 *)data_0022FCE0->func_000128C0(ownerId);
    if (owner) {
        value_130 = owner->func_00107AB0();
    }
    unknown_048 = 0;
    value_11c = 1.0f;
    unknown_12c = 0;
    value_120 = 1.0f;
    unknown_04c = 0;
    unknown_050 = 0;
    value_84 = 0x1555;
    switch (first) {
    case 1:
        sprite = (Sprite_00100F40 *)func_00025700(0xb, 0, 1, 1);
        break;
    case 2:
        sprite = (Sprite_00100F40 *)func_00025700(0xb, 0, 1, 3);
        break;
    case 3:
        sprite = (Sprite_00100F40 *)func_00025700(0xb, 0, 1, 0xb);
        break;
    case 4:
        sprite = (Sprite_00100F40 *)func_00025700(0xb, 0, 1, 0xc);
        secondSprite = (Sprite_00100F40 *)func_00025700(0xb, 0, 1, 0xd);
        break;
    default:
        sprite = (Sprite_00100F40 *)func_00025700(0xb, 0, 1, 0);
        break;
    }
    if (sprite) {
        sprite->flags &= ~8;
        value_11c = sprite->frame->value;
    }
    if (secondSprite) {
        secondSprite->flags &= ~8;
    }
    (this->*data_0021FF98[state])();
    scale[0] = 1.0f;
    scale[1] = 1.0f;
    scale[2] = 1.0f;
    unknown_0a0[0] = 0.0f;
    unknown_0a0[1] = 0.0f;
    unknown_0a0[2] = 0.0f;
}
