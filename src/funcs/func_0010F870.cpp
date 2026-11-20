/* sym: ??0Object_0010F950@@QAE@PAUNode@@HIHH@Z = 0x0010F870 */
/* sym: ??1Object_0010F950@@UAE@XZ = 0x0010F950 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ?func_00011C90@Object_0010F950@@UAEXXZ = 0x0010F960 */
/* sym: ?func_00011C80@Object_0010F950@@UAEXH@Z = 0x0010FA60 */
/* sym: ?func_00011C90_2@Object_0010F950@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_1@Object_0010F950@@UAEXH@Z = 0x000B3DE0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

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


// A sprite from func_00025700: flags at 0x24.
struct Sprite_0010F870 {
    char unknown_00[0x24];
    unsigned int flags;
};

void *func_00025700(unsigned int index, int first, int second, int third);

extern Vector3 data_00220A58;

// A direct child of Node (table 0x1D2538, destructor func_0010F950).
struct Object_0010F950 : Node {
    Object_0010F950(Node *owner, int id, unsigned int flags, int value, int mode);
    virtual ~Object_0010F950();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);

    int unknown_040;
    int value;
    int mode;
    int value_4c;
    Sprite_0010F870 *sprites[6];
    int state;
    int unknown_6c;
    char unknown_070[4];
    Vector3 position;
    int unknown_80;
};

// Keeps the value at 0x44 and the mode at 0x48, the position from 0x220A58, clears 0x68, 0x4c, 0x80 and 0x6c; mode 0
// starts in state 3 with the value at 0x4c. Then the six sprites 0xf4 to 0xf9 of set 0xa (func_00025700), each with
// bit 0 of its flags at 0x24 set.
Object_0010F950::Object_0010F950(Node *owner, int id, unsigned int flags, int value, int mode) : Node(owner, id, flags)
{
    this->value = value;
    this->mode = mode;
    position.x = data_00220A58.x;
    position.y = data_00220A58.y;
    position.z = data_00220A58.z;
    state = 0;
    value_4c = 0;
    unknown_80 = 0;
    unknown_6c = 0;
    if (mode == 0) {
        value_4c = value;
        state = 3;
    }
    for (int i = 0; i < 6; i++) {
        sprites[i] = (Sprite_0010F870 *)func_00025700(0xa, 0, 1, i + 0xf4);
        if (sprites[i]) {
            sprites[i]->flags &= ~1;
            sprites[i]->flags |= 1;
        }
    }
}
