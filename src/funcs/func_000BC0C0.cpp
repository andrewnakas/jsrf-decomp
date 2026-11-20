/* sym: ??1Object_000BC0C0@@UAE@XZ = 0x000BC0C0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000BC0C0@@UAEXXZ = 0x000BCF40 */
/* sym: ?func_00011C90_1@Object_000BC0C0@@UAEXXZ = 0x000BC160 */
/* sym: ?func_00011C80@Object_000BC0C0@@UAEXH@Z = 0x000BC7E0 */
/* sym: ?func_00011C90_2@Object_000BC0C0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_3@Object_000BC0C0@@UAEXXZ = 0x000AEE80 */
/* sym: ?func_00011C80_1@Object_000BC0C0@@UAEXH@Z = 0x000AE660 */
/* sym: ?func_00011C80_3@Object_000BC0C0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000BC0C0@@UAEXH@Z = 0x000B3DE0 */
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
struct Entry_000BC0C0 {
    int used;
    char unknown_004[0x1b4];
    void *buffer;
    char unknown_1bc[0x14];
};

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CDAA0).
struct Object_000BC0C0 : Node {
    virtual ~Object_000BC0C0();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_040[4];
    Entry_000BC0C0 *entries;
    unsigned int count;
};

// Frees the buffer of each of the entries at 0x44 that is in use and has one, then the entries.
Object_000BC0C0::~Object_000BC0C0()
{
    if (entries) {
        for (unsigned int i = 0; i < count; i++) {
            if (entries[i].used && entries[i].buffer) {
                operator delete(entries[i].buffer);
            }
        }
        delete[] entries;
    }
}
