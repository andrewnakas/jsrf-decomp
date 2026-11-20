/* sym: ??1Object_000F08E0@@UAE@XZ = 0x000F0A40 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000F08E0@@UAEXXZ = 0x000F0AC0 */
/* sym: ?func_00011C80@Object_000F08E0@@UAEXH@Z = 0x000F0B00 */
/* sym: ?func_00011C80_3@Object_000F08E0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000F08E0@@UAEXH@Z = 0x000B3DE0 */
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
    void func_00060810(int key);
};

// A direct child of Node (table 0x1CEFE8, constructor func_000F08E0).
struct Object_000F08E0 : Node {
    virtual ~Object_000F08E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_040[0x30];
    int firstKey;
    int secondKey;
};

// Passes the keys at 0x74 and 0x70 to func_00060810 of object 0xe8, when it exists.
Object_000F08E0::~Object_000F08E0()
{
    Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (object) {
        object->func_00060810(secondKey);
        object->func_00060810(firstKey);
    }
}
