/* sym: ??1Object_00097350@@UAE@XZ = 0x00097250 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_00097350@@UAEXXZ = 0x000972C0 */
/* sym: ?func_00011C90_2@Object_00097350@@UAEXXZ = 0x00097350 */
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

// The child of Node whose table is at 0x1CD420 (constructor func_00097190).
struct Object_00097350 : Node {
    virtual ~Object_00097350();
    virtual void func_00011C90();
    virtual void func_00011C90_2();

    int unknown_040;
    int key;
};

// Hands the key at 0x44, when there is one (not negative), to func_000607B0 of object 0xe8.
Object_00097350::~Object_00097350()
{
    Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (object && key >= 0) {
        object->func_000607B0(key);
    }
}
