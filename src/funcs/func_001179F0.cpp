/* sym: ??0Object_00117A30@@QAE@PAUNode@@HI@Z = 0x001179F0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_00117A30@@UAE@XZ = 0x00117A30 */
/* sym: ?func_00011C90@Object_00117A30@@UAEXXZ = 0x00117AB0 */
extern "C" void *memset(void *destination, int value, unsigned int size);

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

// The class whose table is at 0x1D77B8: overrides slot 1 of Node. Its constructor clears the 131 words from +0x44
// on.
struct Object_00117A30 : Node {
    Object_00117A30(Node *owner, int id, unsigned int flags);
    virtual ~Object_00117A30();
    virtual void func_00011C90();

    int words[0x83];
};

Object_00117A30::Object_00117A30(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
{
    memset(words, 0, sizeof(words));
}
