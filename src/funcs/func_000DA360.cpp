/* sym: ??1Object_000DA3E0@@UAE@XZ = 0x000DA360 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000DA3E0@@UAEXXZ = 0x000DA8D0 */
/* sym: ?func_00011C90_1@Object_000DA3E0@@UAEXXZ = 0x000DA700 */
struct Object_00016200 {
    void func_00019760(void *pointer);
};

extern Object_00016200 data_0022FCE8;

int func_001186D0(int handle);

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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};

struct Entry_000DA360 {
    int kind;
    int size;
    void *pointer;
    char unknown_0c[0x18];
};

// The child of Node whose table is at 0x1CE658 (constructor func_000DA1E0): overrides slots 1 and 2.
struct Object_000DA3E0 : Node {
    virtual ~Object_000DA3E0();
    virtual void func_00011C90();
    virtual void func_00011C90_1();

    char unknown_40[0x428];
    Entry_000DA360 entries[16];
    char unknown_6a8[0x18];
    int handle;
};

// Releases the handle at 0x6c0, then frees the pointers of the 16 entries at 0x468 that hold one.
Object_000DA3E0::~Object_000DA3E0()
{
    func_001186D0(handle);
    for (int i = 0; i < 16; i++) {
        if (entries[i].pointer) {
            data_0022FCE8.func_00019760(entries[i].pointer);
        }
    }
}
