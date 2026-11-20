/* sym: ??1Object_00100770@@UAE@XZ = 0x00100710 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_00100770@@UAEXXZ = 0x00100770 */
/* sym: ?func_00011C80@Object_00100770@@UAEXH@Z = 0x00100D80 */
/* sym: ?func_00011C90_2@Object_00100770@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_4@Object_00100770@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_6@Object_00100770@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_8@Object_00100770@@UAEXXZ = 0x000AECC0 */
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
void func_00077F70(int which, int set);

// The child of Node whose table is at 0x1D1D00 (constructor func_001005F0).
struct Object_00100770 : Node {
    virtual ~Object_00100770();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();

    char unknown_040[0x20];
    int mode;
};

// In mode 2 (at 0x60) calls func_00077F70(1, 0).
Object_00100770::~Object_00100770()
{
    if (mode == 2) {
        func_00077F70(1, 0);
    }
}
