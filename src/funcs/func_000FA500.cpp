/* sym: ??1Object_000FAB60@@UAE@XZ = 0x000FA500 */
/* sym: ??1Object_000FDDC0@@UAE@XZ = 0x000FD9B0 */
/* sym: ?func_00011C90_2@Object_000FDDC0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_1@Object_000FDDC0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_6@Object_000FDDC0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_3@Object_000FDDC0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_8@Object_000FDDC0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_4@Object_000FDDC0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90@Object_000FAB60@@UAEXXZ = 0x000FADA0 */
/* sym: ?func_00011C80@Object_000FAB60@@UAEXH@Z = 0x000FA580 */
/* sym: ?func_00011C90_4@Object_000FAB60@@UAEXXZ = 0x000AECC0 */
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

// The child of that class whose table is at 0x1D08E0 (constructor func_000FAB60); it keeps the base's slot 16.
struct Object_000FAB60 : Object_000FDDC0 {
    virtual ~Object_000FAB60();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_4();

    char unknown_048[0x70];
    void *data;
};

// Calls func_00116810 and func_001166B0(0), then frees the buffer at 0xb8 and clears it.
Object_000FAB60::~Object_000FAB60()
{
    func_00116810();
    func_001166B0(0);
    if (data) {
        operator delete(data);
        data = 0;
    }
}
