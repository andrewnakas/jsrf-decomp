/* sym: ??0Object_000FF9B0@@QAE@PAUNode@@HIH@Z = 0x000FF8E0 */
/* sym: ??1Object_000FF9B0@@UAE@XZ = 0x000FF9B0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000FF9B0@@UAEXXZ = 0x000FF9C0 */
/* sym: ?func_00011C80@Object_000FF9B0@@UAEXH@Z = 0x000FFA80 */
/* sym: ?func_00011C90_2@Object_000FF9B0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_1@Object_000FF9B0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_6@Object_000FF9B0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_3@Object_000FF9B0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_8@Object_000FF9B0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_4@Object_000FF9B0@@UAEXH@Z = 0x000B3DE0 */
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

// The parent the constructor marks (bit 30 of its flags at 0x80).
struct Parent_000FF8E0 {
    char unknown_00[0x80];
    unsigned int flags;
};

// A direct child of Node (table 0x1D1C70, destructor func_000FF9B0): three sprites from func_00025700, the second
// chosen by the value at 0x44.
struct Object_000FF9B0 : Node {
    Object_000FF9B0(Node *owner, int id, unsigned int flags, int value);
    virtual ~Object_000FF9B0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C80_4(int argument);

    int unknown_40;
    int value;
    void *sprite_48;
    void *sprite_4c;
    Vector3 position;
    void *sprite_5c;
    int unknown_60;
    int unknown_64;
    int unknown_68;
    int unknown_6c;
};

extern Vector3 data_00220A58;

void *func_00025700(unsigned int index, int first, int second, int third);

// Keeps the value, clears its fields, copies the position at 0x220A58, loads the three sprites and sets bit 30 of
// the parent's flags at 0x80.
Object_000FF9B0::Object_000FF9B0(Node *owner, int id, unsigned int flags, int value) : Node(owner, id, flags)
{
    this->value = value;
    sprite_48 = 0;
    sprite_4c = 0;
    position.x = data_00220A58.x;
    position.y = data_00220A58.y;
    position.z = data_00220A58.z;
    unknown_68 = 0;
    unknown_6c = 0;
    unknown_64 = 0;
    sprite_48 = func_00025700(0xa, 0, 1, 2);
    sprite_4c = func_00025700(0xd, this->value, 0, 0);
    sprite_5c = func_00025700(0xa, 0, 2, 0x14);
    ((Parent_000FF8E0 *)parent)->flags |= 0x40000000;
}
