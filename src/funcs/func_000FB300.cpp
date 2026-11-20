/* sym: ??1Object_000FB530@@UAE@XZ = 0x000FB300 */
/* sym: ??1Object_000FDDC0@@UAE@XZ = 0x000FD9B0 */
/* sym: ?func_00011C90_2@Object_000FDDC0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_1@Object_000FDDC0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_6@Object_000FDDC0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_3@Object_000FDDC0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_8@Object_000FDDC0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_4@Object_000FDDC0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90@Object_000FB530@@UAEXXZ = 0x000FB9F0 */
/* sym: ?func_00011C80@Object_000FB530@@UAEXH@Z = 0x000FB380 */
/* sym: ?func_000FDDC0@Object_000FB530@@UAEXXZ = 0x000FB530 */
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
void func_00116810();
void func_001166B0(int argument);

// The child of Node whose table is at 0x1D1BA8 (destructor func_000FD9B0); slot 16 is func_000FDDC0.
struct Object_000FDDC0 : Node {
    virtual ~Object_000FDDC0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C80_4(int argument);
    virtual void func_000FDDC0();

    char unknown_040[4];
    void *buffer;
};

// The child of that class whose table is at 0x1D1B20 (constructor func_000FB870).
struct Object_000FB530 : Object_000FDDC0 {
    virtual ~Object_000FB530();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_000FDDC0();

    char unknown_048[0x6c];
    void *data;
};

// Calls func_00116810 and func_001166B0(0), then frees the buffer at 0xb4 and clears it.
Object_000FB530::~Object_000FB530()
{
    func_00116810();
    func_001166B0(0);
    if (data) {
        operator delete(data);
        data = 0;
    }
}
