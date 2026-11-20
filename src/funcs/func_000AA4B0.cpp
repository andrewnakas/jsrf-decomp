/* sym: ??1Object_000AA4B0@@UAE@XZ = 0x000AA4B0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000AA4B0@@UAEXXZ = 0x000AA550 */
/* sym: ?func_00011C90_1@Object_000AA4B0@@UAEXXZ = 0x000AAB90 */
/* sym: ?func_00011C80@Object_000AA4B0@@UAEXH@Z = 0x000AAFB0 */
/* sym: ?func_00011C90_2@Object_000AA4B0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_3@Object_000AA4B0@@UAEXXZ = 0x000AEE80 */
/* sym: ?func_00011C80_1@Object_000AA4B0@@UAEXH@Z = 0x000AE660 */
/* sym: ?func_00011C80_3@Object_000AA4B0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000AA4B0@@UAEXH@Z = 0x000B3DE0 */
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
struct Entry_000AA4B0 {
    char unknown_000[0x1a4];
    void *buffer;
    char unknown_1a8[0x14];
};

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD658).
struct Object_000AA4B0 : Node {
    virtual ~Object_000AA4B0();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_040[4];
    Entry_000AA4B0 *entries;
    unsigned int count;
};

// Frees the buffer of each of the entries at 0x44 that has one, then the entries.
Object_000AA4B0::~Object_000AA4B0()
{
    if (entries) {
        for (unsigned int i = 0; i < count; i++) {
            if (entries[i].buffer) {
                operator delete(entries[i].buffer);
            }
        }
        delete[] entries;
    }
}
