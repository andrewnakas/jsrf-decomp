/* sym: ??1Object_000D0680@@UAE@XZ = 0x000D07A0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000D0680@@UAEXXZ = 0x000D0800 */
/* sym: ?func_00011C80@Object_000D0680@@UAEXH@Z = 0x000D08F0 */
/* sym: ?func_00011C80_3@Object_000D0680@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000D0680@@UAEXH@Z = 0x000B3DE0 */
struct Object_00016200 {
    void func_00019760(void *pointer);
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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};

// The class whose table is at 0x1CE400: overrides slots 1, 3 of Node; slots 12, 15 hold folded thunks.
struct Object_000D0680 : Node {
    virtual ~Object_000D0680();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_40[0x3c];
    void *handle;
};

// Frees the pointer at 0x7c, if any, through data_0022FCE8.
Object_000D0680::~Object_000D0680()
{
    if (handle) {
        data_0022FCE8.func_00019760(handle);
    }
}
