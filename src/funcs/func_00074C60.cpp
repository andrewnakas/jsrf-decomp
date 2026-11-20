/* sym: ??1Object_00074C60@@UAE@XZ = 0x00074C60 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_00074C60@@UAEXXZ = 0x00074C70 */
/* sym: ?func_00011C80@Object_00074C60@@UAEXH@Z = 0x00074CB0 */
/* sym: ?func_00011C80_1@Object_00074C60@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_3@Object_00074C60@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_00074C60@@UAEXH@Z = 0x000B3DE0 */
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

// The class whose table is at 0x1CCC98: overrides slots 1 (74C70), 3 (74CB0), 6 (B3DE0), 12 (B3DE0), 15 (B3DE0).
struct Object_00074C60 : Node {
    virtual ~Object_00074C60();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);
};

Object_00074C60::~Object_00074C60()
{
}
