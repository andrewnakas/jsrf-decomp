/* sym: ??1Object_000D01A0@@UAE@XZ = 0x000CFA90 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000D01A0@@UAEXXZ = 0x000D05C0 */
/* sym: ?func_00011C80@Object_000D01A0@@UAEXH@Z = 0x000D02F0 */
/* sym: ?func_00011C80_3@Object_000D01A0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000D01A0@@UAEXH@Z = 0x000B3DE0 */
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

// The parts the constructor func_000D01A0 makes (table 0x1CE3F8, constructor func_000CFB70, destructor
// func_000CFC70): slot 0 is the destructor.
struct Object_000CFB70 {
    virtual ~Object_000CFB70();
};

// A direct child of Node (table 0x1CE3B8, constructor func_000D01A0) with eight parts at 0x48.
struct Object_000D01A0 : Node {
    virtual ~Object_000D01A0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_040[8];
    Object_000CFB70 *parts[8];
};

// Deletes the parts that are there.
Object_000D01A0::~Object_000D01A0()
{
    for (int i = 0; i < 8; i++) {
        if (parts[i]) {
            delete parts[i];
        }
    }
}
