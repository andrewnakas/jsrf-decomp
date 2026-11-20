/* sym: ??1Object_000F37B0@@UAE@XZ = 0x000F38B0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000F37B0@@UAEXXZ = 0x000F3920 */
/* sym: ?func_00011C80@Object_000F37B0@@UAEXH@Z = 0x000F3A20 */
/* sym: ?func_00011C80_3@Object_000F37B0@@UAEXH@Z = 0x000F3BB0 */
/* sym: ?func_00011C80_4@Object_000F37B0@@UAEXH@Z = 0x000B3DE0 */
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
struct Object_00016200 {
    void func_00019760(void *item);
};

extern Object_00016200 data_0022FCE8;

// One of the 75 entries at 0x76c (0x24 bytes each).
struct Entry_000F37B0 {
    void *item;
    char unknown_04[0x20];
};

// The child of Node whose table is at 0x1CF058 (constructor func_000F37B0).
struct Object_000F37B0 : Node {
    virtual ~Object_000F37B0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_040[0x72c];
    Entry_000F37B0 entries[75];
};

// Hands each entry's item at 0x76c (75 entries of 0x24 bytes) that is there to func_00019760 of data_0022FCE8.
Object_000F37B0::~Object_000F37B0()
{
    for (int i = 0; i < 75; i++) {
        if (entries[i].item) {
            data_0022FCE8.func_00019760(entries[i].item);
        }
    }
}
