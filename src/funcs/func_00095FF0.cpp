/* sym: ??1Object_00095FC0@@UAE@XZ = 0x00095FF0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90_1@Object_00095FC0@@UAEXXZ = 0x00096070 */
/* sym: ?func_00011C90_3@Object_00095FC0@@UAEXXZ = 0x00096F60 */
struct Node {
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

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    void func_000607B0(int key);
};

// One of six direct children of Node (table 0x1CD2E0, constructor func_00095FC0): overrides slots 2 and 5.
struct Object_00095FC0 : Node {
    virtual ~Object_00095FC0();
    virtual void func_00011C90_1();
    virtual void func_00011C90_3();

    int unknown_40;
    int active;
    int unknown_48;
    int unknown_4c;
    int key;
};

// While the flag at 0x44 is set and object 0xe8 exists, passes it the key at 0x50 (func_000607B0) and clears the
// flag.
Object_00095FC0::~Object_00095FC0()
{
    Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (object && active) {
        object->func_000607B0(key);
        active = 0;
    }
}
