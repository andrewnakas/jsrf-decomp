/* sym: ??0Object_001197F0@@QAE@PAUNode@@HIHHH@Z = 0x001196A0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_001197F0@@UAE@XZ = 0x001197F0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_001197F0@@UAEXXZ = 0x00119EC0 */
/* sym: ?func_00011C80@Object_001197F0@@UAEXH@Z = 0x001199C0 */
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
    char unknown_34[0x10];
};

struct Object_00070850 {
    int func_00070990(int index);
};

// The class whose table is at 0x1D7B60: overrides slots 1 and 3 of Node.
struct Object_001197F0 : Node {
    Object_001197F0(Node *owner, int id, unsigned int flags, int port, int value, int mode);
    virtual ~Object_001197F0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);

    int value_44;
    int port;
    int value_4c;
    int value_50;
    int mode;
    int value_58;
    int value_5c;
    int current;
    int value_64;
    int value_68;
    void *sprites[8];
    float x;
    float y;
    float z;
};

void *func_00025700(unsigned int index, int first, int second, int third);

// Builds the node for controller `port` on `owner`: keeps the port at +0x48 and +0x60, `value` at +0x4c and
// `mode` at +0x54, looks up its sprites in group 0x12 (the port's own entry, 14 further on when the owner's
// func_00070990 gives nonzero for the port) and places it at (-32, 24, 1220).
Object_001197F0::Object_001197F0(Node *owner, int id, unsigned int flags, int port, int value, int mode)
    : Node(owner, id, flags)
{
    this->port = port;
    value_4c = value;
    this->mode = mode;
    current = port;
    value_5c = 0;
    value_58 = -1;
    value_50 = 0;
    value_44 = 0;
    if (((Object_00070850 *)owner)->func_00070990(port)) {
        sprites[0] = func_00025700(0x12, 1, 2, this->port + 14);
    } else {
        sprites[0] = func_00025700(0x12, 1, 2, this->port + 3);
    }
    sprites[1] = func_00025700(0x12, 1, 2, 2);
    sprites[3] = func_00025700(0x12, 1, 2, 0xb);
    sprites[2] = func_00025700(0x12, 1, 2, 1);
    sprites[4] = func_00025700(0x12, 1, 4, 1);
    sprites[5] = func_00025700(0x12, 1, 4, 2);
    sprites[6] = func_00025700(0x12, 1, 4, 3);
    sprites[7] = func_00025700(0x12, 1, 4, 4);
    value_68 = 0;
    x = -32.0f;
    y = 24.0f;
    z = 1220.0f;
}
