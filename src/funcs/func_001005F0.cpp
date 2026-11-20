/* sym: ??0Object_00100770@@QAE@PAUNode@@HIHH@Z = 0x001005F0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_00100770@@UAE@XZ = 0x00100710 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_00100770@@UAEXXZ = 0x00100770 */
/* sym: ?func_00011C80@Object_00100770@@UAEXH@Z = 0x00100D80 */
/* sym: ?func_00011C90_2@Object_00100770@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_4@Object_00100770@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_6@Object_00100770@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_8@Object_00100770@@UAEXXZ = 0x000AECC0 */
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

void *func_00025700(unsigned int index, int first, int second, int third);

// A direct child of Node (table 0x1D1D00, destructor func_00100710).
struct Object_00100770 : Node {
    Object_00100770(Node *owner, int id, unsigned int flags, int value, int mode);
    virtual ~Object_00100770();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();

    char unknown_040[4];
    int unknown_44;
    char unknown_048[4];
    void *sprite;
    void *shadow;
    int unknown_54;
    void *first;
    void *second;
    int mode;
    int unknown_64;
    int unknown_68;
    char unknown_06c[8];
    float value_74;
    float value_78;
    float value_7c;
    int unknown_80;
    int unknown_84;
    int unknown_88;
    int unknown_8c;
    int value;
};

// Keeps the value and the mode and loads the sprites of the mode (func_00025700): mode 0 sprite 0x39 and shadow 0,
// mode 1 0x7b and 0x13, mode 2 0xfe and the pair 0x2d/0x2e (the first of which is the shadow).
Object_00100770::Object_00100770(Node *owner, int id, unsigned int flags, int value, int mode)
    : Node(owner, id, flags)
{
    this->value = value;
    this->mode = mode;
    sprite = 0;
    shadow = 0;
    unknown_54 = 0;
    unknown_64 = -1;
    unknown_8c = 0;
    unknown_44 = 0;
    unknown_80 = 0;
    unknown_84 = 0;
    unknown_88 = 0;
    value_74 = -32.0f;
    value_78 = 24.0f;
    value_7c = 1220.0f;
    unknown_68 = 0;
    switch (mode) {
    case 0:
        sprite = func_00025700(0xa, 0, 1, 0x39);
        shadow = func_00025700(0xa, 0, 2, 0);
        break;
    case 1:
        sprite = func_00025700(0xa, 0, 1, 0x7b);
        shadow = func_00025700(0xa, 0, 2, 0x13);
        break;
    case 2:
        sprite = func_00025700(0xa, 0, 1, 0xfe);
        first = func_00025700(0xa, 0, 2, 0x2d);
        second = func_00025700(0xa, 0, 2, 0x2e);
        shadow = first;
        break;
    }
}
