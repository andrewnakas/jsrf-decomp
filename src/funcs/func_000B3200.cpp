/* sym: ??1Object_000B3200@@UAE@XZ = 0x000B3200 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000B3200@@UAEXXZ = 0x000B3270 */
/* sym: ?func_00011C90_1@Object_000B3200@@UAEXXZ = 0x000B3970 */
/* sym: ?func_00011C80@Object_000B3200@@UAEXH@Z = 0x000B3C30 */
/* sym: ?func_00011C90_2@Object_000B3200@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_3@Object_000B3200@@UAEXXZ = 0x000AEE80 */
/* sym: ?func_00011C80_1@Object_000B3200@@UAEXH@Z = 0x000AE660 */
/* sym: ?func_00011C80_3@Object_000B3200@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000B3200@@UAEXH@Z = 0x000B3DE0 */
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
void func_0005DAA0(void *pointer);

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD878).
struct Object_000B3200 : Node {
    virtual ~Object_000B3200();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_040[0x98];
    void *block;
    char unknown_0dc[0x128];
    void *buffer;
};

// Frees the buffer at 0x204 when there is one, then passes the block at 0xd8 to func_0005DAA0 when there is one.
Object_000B3200::~Object_000B3200()
{
    if (buffer) {
        operator delete(buffer);
    }
    if (block) {
        func_0005DAA0(block);
    }
}
