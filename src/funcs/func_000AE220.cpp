/* sym: ??1Object_000AE220@@UAE@XZ = 0x000AE220 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000AE220@@UAEXXZ = 0x000AE290 */
/* sym: ?func_00011C90_1@Object_000AE220@@UAEXXZ = 0x000AE430 */
/* sym: ?func_00011C80@Object_000AE220@@UAEXH@Z = 0x000AE560 */
/* sym: ?func_00011C90_2@Object_000AE220@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_3@Object_000AE220@@UAEXXZ = 0x000AEE80 */
/* sym: ?func_00011C80_1@Object_000AE220@@UAEXH@Z = 0x000AE660 */
/* sym: ?func_00011C80_3@Object_000AE220@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000AE220@@UAEXH@Z = 0x000B3DE0 */
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
// An object with a virtual destructor.
struct Part_000AE220 {
    virtual ~Part_000AE220();
};

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD730).
struct Object_000AE220 : Node {
    virtual ~Object_000AE220();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_040[0xb4];
    Part_000AE220 *part;
    char unknown_0f8[0xc4];
    void *buffer;
};

// Frees the buffer at 0x1bc when there is one, then deletes the object at 0xf4.
Object_000AE220::~Object_000AE220()
{
    if (buffer) {
        operator delete(buffer);
    }
    delete part;
}
