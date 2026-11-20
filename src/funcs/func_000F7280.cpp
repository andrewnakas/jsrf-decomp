/* sym: ??0Object_000F7280@@QAE@PAUNode@@HI@Z = 0x000F7280 */
/* sym: ??1Object_000F7280@@UAE@XZ = 0x000F7320 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000F7280@@UAEXXZ = 0x000F7390 */
/* sym: ?func_00011C80@Object_000F7280@@UAEXH@Z = 0x000F73D0 */
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

// A sprite from func_00025700 (flags at 0x24).
struct Sprite_000F7280 {
    char unknown_00[0x24];
    unsigned int flags;
};

// The child of Node whose table is at 0x1CF2F8 (destructor func_000F7320).
struct Object_000F7280 : Node {
    Object_000F7280(Node *owner, int id, unsigned int flags);
    virtual ~Object_000F7280();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);

    int unknown_040;
    Sprite_000F7280 *sprite;
    short *range;
    float time;
};

void *func_00025700(unsigned int index, int first, int second, int third);

// Loads its sprite (with bit 0 of its flags cleared, then set) and the motion range, and starts the time at 0.
Object_000F7280::Object_000F7280(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
{
    sprite = (Sprite_000F7280 *)func_00025700(0xa, 0, 1, 0x103);
    if (sprite) {
        sprite->flags &= ~1;
        sprite->flags |= 1;
    }
    range = (short *)func_00025700(0xa, 0, 2, 0x30);
    time = 0.0f;
}
