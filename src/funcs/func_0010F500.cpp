/* sym: ??0Object_0010F620@@QAE@PAUNode@@HI@Z = 0x0010F500 */
/* sym: ??1Object_0010F620@@UAE@XZ = 0x0010F610 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ?func_00011C90@Object_0010F620@@UAEXXZ = 0x0010F620 */
/* sym: ?func_00011C80@Object_0010F620@@UAEXH@Z = 0x0010F670 */
/* sym: ?func_00011C90_2@Object_0010F620@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_1@Object_0010F620@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_4@Object_0010F620@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_2@Object_0010F620@@UAEXH@Z = 0x000B3DE0 */
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

    Node *func_00011BD0();
};


struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// What object 9 fills in (func_0004D460; 0x118 bytes): a pointer at 0x114.
struct Info_0004D460 {
    char unknown_000[0x114];
    int *value;
};

void func_0004EA50(Info_0004D460 *info);

// The root node func_00011BD0 gives: a value at 0xe0.
struct Root_0010F500 {
    char unknown_00[0xe0];
    int value_e0;
};

void *func_00025700(unsigned int index, int first, int second, int third);

extern Vector3 data_00220A58;

// A direct child of Node (table 0x1D24F0, destructor func_0010F610).
struct Object_0010F620 : Node {
    Object_0010F620(Node *owner, int id, unsigned int flags);
    virtual ~Object_0010F620();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);

    int unknown_040;
    void *sprites[3];
    Vector3 position;
    int value_5c;
    int value_60;
    int value_64;
    int value_68;
    int value_6c;
};

// Takes 0x5c from the value object 9's info points at (func_0004EA50; 0 without it), the position from 0x220A58,
// 0x68 from the root's 0xe0 (func_00011BD0), clears its other fields and loads sprites 4, 7 and 5 of set 0xa.
Object_0010F620::Object_0010F620(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
{
    Root_0010F500 *root = (Root_0010F500 *)func_00011BD0();
    value_5c = 0;
    if (data_0022FCE0->func_000128C0(9)) {
        Info_0004D460 info;
        func_0004EA50(&info);
        if (info.value) {
            value_5c = *info.value;
        }
    }
    sprites[0] = 0;
    sprites[1] = 0;
    sprites[2] = 0;
    position.x = data_00220A58.x;
    position.y = data_00220A58.y;
    position.z = data_00220A58.z;
    value_60 = 0;
    value_64 = 0;
    value_68 = root->value_e0;
    value_6c = 0;
    sprites[0] = func_00025700(0xa, 0, 1, 4);
    sprites[1] = func_00025700(0xa, 0, 1, 7);
    sprites[2] = func_00025700(0xa, 0, 1, 5);
}
