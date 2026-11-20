/* sym: ??0Object_000FDDC0@@QAE@PAUNode@@HIHHHPBDHH@Z = 0x000FD870 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??0Object_000FF9B0@@QAE@PAUNode@@HIH@Z = 0x000FF8E0 */
/* sym: ??1Object_000FDDC0@@UAE@XZ = 0x000FD9B0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000FDDC0@@UAEXXZ = 0x000FDA20 */
/* sym: ?func_00011C80@Object_000FDDC0@@UAEXH@Z = 0x000FDCD0 */
/* sym: ?func_00011C90_2@Object_000FDDC0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_1@Object_000FDDC0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_6@Object_000FDDC0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_3@Object_000FDDC0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_8@Object_000FDDC0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_4@Object_000FDDC0@@UAEXH@Z = 0x000B3DE0 */
extern "C" void *memcpy(void *destination, const void *source, unsigned int size);

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

// A direct child of Node (table 0x1D1C70): three sprites, the second chosen by the value.
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

    char unknown_40[0x30];
};

extern Vector3 data_00220A58;

void *func_00025700(unsigned int index, int first, int second, int third);
int func_000FE690(const char *text);

// A direct child of Node (table 0x1D1BA8, destructor func_000FD9B0) with a copy of a "$r"-ended text.
struct Object_000FDDC0 : Node {
    Object_000FDDC0(Node *owner, int id, unsigned int flags, int kind, int value, int first, const char *text,
                    int second, int third);
    virtual ~Object_000FDDC0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C80_4(int argument);
    virtual void func_000FDDC0();

    char unknown_040[4];
    char *buffer;
    void *sprite;
    Vector3 position;
    char unknown_058[0xc];
    int unknown_64;
    int unknown_68;
    int first;
    int second;
    int third;
    int unknown_78;
    int kind;
    int unknown_80;
    char unknown_084[8];
    int value;
};

// Keeps a copy of the text (up to its "$r" end, func_000FE690), the kind, the value and the three numbers, starts
// at the position 0x220A58 and loads the sprite of its kind (func_00025700); kind 0 also gets an Object_000FF9B0
// child with the value.
Object_000FDDC0::Object_000FDDC0(Node *owner, int id, unsigned int flags, int kind, int value, int first,
                                 const char *text, int second, int third)
    : Node(owner, id, flags)
{
    this->kind = kind;
    this->value = value;
    buffer = 0;
    int length = func_000FE690(text);
    buffer = (char *)operator new(length);
    memcpy(buffer, text, length);
    this->second = second;
    sprite = 0;
    this->third = third;
    unknown_80 = 0;
    unknown_64 = 0;
    unknown_68 = 0;
    position.x = data_00220A58.x;
    position.y = data_00220A58.y;
    position.z = data_00220A58.z;
    this->first = first;
    switch (this->kind) {
    case 0:
        sprite = func_00025700(0xa, 0, 1, 0);
        new Object_000FF9B0(this, -1, 0x100, this->value);
        break;
    case 1:
        sprite = func_00025700(0xa, 0, 1, 1);
        break;
    }
    unknown_78 = 0;
}
