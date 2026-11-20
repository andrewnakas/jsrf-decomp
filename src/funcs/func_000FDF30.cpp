/* sym: ??1Object_000FDF30@@UAE@XZ = 0x000FDF30 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C80@Object_000FDF30@@UAEXH@Z = 0x000FEDC0 */
/* sym: ?func_00011C90_2@Object_000FDF30@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_1@Object_000FDF30@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_2@Object_000FDF30@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_6@Object_000FDF30@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_3@Object_000FDF30@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_8@Object_000FDF30@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_4@Object_000FDF30@@UAEXH@Z = 0x000B3DE0 */
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

// The camera node (constructor func_00012170): its table repeats Node's slots; its implicit destructor is at
// 0x121D0.
struct Object_00012170 : Node {
    char unknown_040[0x58];
};

// An entry of the list at 0xdc; the constructor clears only the buffer.
struct Entry_000FDF30 {
    int unknown_0[2];
    void *buffer;
    char unknown_c[0xc];
};

// The child of the camera node whose table is at 0x1D1BF0 (constructor func_000FE740; object 0x1165).
struct Object_000FDF30 : Object_00012170 {
    virtual ~Object_000FDF30();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C80_4(int argument);

    int unknown_098[3];
    int ids[7];
    int unknown_0c0[7];
    Entry_000FDF30 entries[7];
    int table[5][16];
    char unknown_2c4[0x80];
};

// Frees the buffers of the seven entries at 0xdc.
Object_000FDF30::~Object_000FDF30()
{
    for (int i = 0; i < 7; i++) {
        if (entries[i].buffer) {
            operator delete(entries[i].buffer);
            entries[i].buffer = 0;
        }
    }
}
