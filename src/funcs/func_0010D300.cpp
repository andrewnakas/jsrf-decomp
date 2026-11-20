/* sym: ??1Object_0010CF70@@UAE@XZ = 0x0010D300 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_0010CF70@@UAEXXZ = 0x0010D380 */
/* sym: ?func_00011C80@Object_0010CF70@@UAEXH@Z = 0x0010D480 */
/* sym: ?func_00011C90_2@Object_0010CF70@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_4@Object_0010CF70@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_6@Object_0010CF70@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_8@Object_0010CF70@@UAEXXZ = 0x000AECC0 */
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
// The interfaces the node holds at 0x44 and 0x168; slot 2 releases one.
struct Interface_0010CF70 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

// The child of Node whose table is at 0x1D2328 (constructor func_0010CF70).
struct Object_0010CF70 : Node {
    virtual ~Object_0010CF70();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();

    char unknown_040[4];
    Interface_0010CF70 *first;
    char unknown_048[0x120];
    Interface_0010CF70 *second;
};

// Releases the interfaces at 0x44 and 0x168 when they are there, and clears them.
Object_0010CF70::~Object_0010CF70()
{
    if (first) {
        first->slot2();
        first = 0;
    }
    if (second) {
        second->slot2();
        second = 0;
    }
}
