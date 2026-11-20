/* sym: ??0Object_00080070@@QAE@PAUNode@@HIHPBH@Z = 0x00080020 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_00080070@@UAE@XZ = 0x00080070 */
/* sym: ?func_00011C90@Object_00080070@@UAEXXZ = 0x00080080 */
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

// The class whose table is at 0x1CD048 (0x54 bytes): a countdown that, when it runs out, writes its pair of values
// into the entry registered under its key and kills itself with everything below it.
struct Object_00080070 : Node {
    Object_00080070(Node *owner, int id, unsigned int flags, int key, const int *value);
    virtual ~Object_00080070();
    virtual void func_00011C90();

    int timer;
    int key;
    int value[2];
};

Object_00080070::Object_00080070(Node *owner, int id, unsigned int flags, int key, const int *value)
    : Node(owner, id, flags)
{
    this->key = key;
    timer = 60;
    this->value[0] = value[0];
    this->value[1] = value[1];
}
