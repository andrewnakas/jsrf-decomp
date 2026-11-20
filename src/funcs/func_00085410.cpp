/* sym: ??1Object_00086060@@UAE@XZ = 0x00085410 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_00086060@@UAEXXZ = 0x00085480 */
/* sym: ?func_00011C90_1@Object_00086060@@UAEXXZ = 0x000854B0 */
/* sym: ?func_00011C80@Object_00086060@@UAEXH@Z = 0x000854E0 */
void func_00013FC0(int id);

struct Object_00016200 {
    void func_00019760(void *item);
};

extern Object_00016200 data_0022FCE8;

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

// The class whose table is at 0x1CD0C0: overrides slots 1 (85480), 2 (854B0), 3 (854E0).
struct Object_00086060 : Node {
    virtual ~Object_00086060();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);

    char unknown_044[0x5c];
    int unknown_a0;
    char unknown_0a4[0xb0];
    void *unknown_154;
};

// Takes out the object whose id is at +0xa0 (func_00013FC0) and hands the item at +0x154, when there is one, to
// func_00019760 of 0x22FCE8.
Object_00086060::~Object_00086060()
{
    func_00013FC0(unknown_a0);
    if (unknown_154) {
        data_0022FCE8.func_00019760(unknown_154);
    }
}
