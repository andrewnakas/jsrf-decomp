/* sym: ??1Object_000AB670@@UAE@XZ = 0x000AB670 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000AB670@@UAEXXZ = 0x000AB740 */
/* sym: ?func_00011C90_1@Object_000AB670@@UAEXXZ = 0x000AC0B0 */
/* sym: ?func_00011C80@Object_000AB670@@UAEXH@Z = 0x000AC950 */
/* sym: ?func_00011C90_2@Object_000AB670@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_3@Object_000AB670@@UAEXXZ = 0x000AEE80 */
/* sym: ?func_00011C80_1@Object_000AB670@@UAEXH@Z = 0x000AE660 */
/* sym: ?func_00011C80_3@Object_000AB670@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000AB670@@UAEXH@Z = 0x000B3DE0 */
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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};
struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Entry_000AB670 {
    char unknown_000[0x13c];
    int id;
    char unknown_140[0x78];
    void *buffer;
    char unknown_1bc[0x14];
};

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD6A0).
struct Object_000AB670 : Node {
    virtual ~Object_000AB670();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_040[4];
    Entry_000AB670 *entries;
    unsigned int count;
};

// For each of the entries at 0x44: unlinks the node its id names (func_00011BE0, then func_00011C20 on the
// node's child) and frees its buffer; then frees the entries.
Object_000AB670::~Object_000AB670()
{
    if (entries) {
        for (unsigned int i = 0; i < count; i++) {
            if (entries[i].id) {
                Node *node = (Node *)data_0022FCE0->func_000128C0(entries[i].id);
                if (node) {
                    node->func_00011BE0(node);
                    node->func_00011C20(node->child);
                }
            }
            if (entries[i].buffer) {
                operator delete(entries[i].buffer);
            }
        }
        delete[] entries;
    }
}
