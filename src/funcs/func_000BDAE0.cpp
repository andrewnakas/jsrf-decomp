/* sym: ??1Object_000BDAE0@@UAE@XZ = 0x000BDAE0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000BDAE0@@UAEXXZ = 0x000BDBA0 */
/* sym: ?func_00011C90_1@Object_000BDAE0@@UAEXXZ = 0x000BDE30 */
/* sym: ?func_00011C80@Object_000BDAE0@@UAEXH@Z = 0x000BDFD0 */
/* sym: ?func_00011C90_2@Object_000BDAE0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_3@Object_000BDAE0@@UAEXXZ = 0x000AEE80 */
/* sym: ?func_00011C80_1@Object_000BDAE0@@UAEXH@Z = 0x000AE660 */
/* sym: ?func_00011C80_3@Object_000BDAE0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000BDAE0@@UAEXH@Z = 0x000B3DE0 */
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

struct Item_00017940;

struct Object_00016200 {
    void func_000178D0(Item_00017940 *item);
};

extern Object_00016200 data_0022FCE8;

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CDAE0).
struct Object_000BDAE0 : Node {
    virtual ~Object_000BDAE0();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_040[0x3c];
    int handle;
    char unknown_080[0x2c];
    int first;
    int second;
    char unknown_0b4[0xc4];
    void *buffer;
    char unknown_17c[0x18];
    Item_00017940 *item;
};

// Frees the buffer at 0x178 when there is one; passes the keys at 0xac and 0xb0 that are not -1 to object 0xe8
// (func_000607B0) when it exists; unregisters the item at 0x194 (func_000178D0 of data_0022FCE8) when the
// handle at 0x7c is not -1.
Object_000BDAE0::~Object_000BDAE0()
{
    Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (buffer) {
        operator delete(buffer);
    }
    if (object) {
        if (first != -1) {
            object->func_000607B0(first);
        }
        if (second != -1) {
            object->func_000607B0(second);
        }
    }
    if (handle != -1) {
        data_0022FCE8.func_000178D0(item);
    }
}
