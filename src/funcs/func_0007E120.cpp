/* sym: ??1Object_0007E120@@UAE@XZ = 0x0007E120 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_0007E120@@UAEXXZ = 0x0007E180 */
/* sym: ?func_00011C90_2@Object_0007E120@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_4@Object_0007E120@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_6@Object_0007E120@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_8@Object_0007E120@@UAEXXZ = 0x000AECC0 */
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
    char unknown_34[0x10];
};

void func_00026080();

// Node child with the table at 0x1CCF78 (id 0x1df3, 0x50 bytes; made by func_0007E260, slot 1 0x7E180; slots 4,
// 7, 10 and 13 hold the folded 0xAECC0).
struct Object_0007E120 : Node {
    virtual ~Object_0007E120();
    virtual void func_00011C90();
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();

    int unknown_44;
    int unknown_48;
    int unknown_4c;
};

// Runs func_00026080 when +0x44 is 1.
Object_0007E120::~Object_0007E120()
{
    if (unknown_44 == 1)
        func_00026080();
}
