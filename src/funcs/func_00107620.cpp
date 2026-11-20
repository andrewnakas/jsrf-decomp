/* sym: ??1Object_00107FE0@@UAE@XZ = 0x00107620 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_00107FE0@@UAEXXZ = 0x00108840 */
/* sym: ?func_00011C80@Object_00107FE0@@UAEXH@Z = 0x00107680 */
/* sym: ?func_00011C90_2@Object_00107FE0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_4@Object_00107FE0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_6@Object_00107FE0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_8@Object_00107FE0@@UAEXXZ = 0x000AECC0 */
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

// The objects with ids 0x115e to 0x1162 (table 0x1D2020; func_00108760 creates one with func_001074B0): func_00106F70
// looks one up by id and calls func_00107B20 on it, as func_00107190 and func_00106F10 call func_00109850 and
// func_00109300.
struct Object_00107FE0 : Node {
    virtual ~Object_00107FE0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();
};

// Takes itself out of the draw links (func_00011BE0) and does the same for its children (func_00011C20).
Object_00107FE0::~Object_00107FE0()
{
    func_00011BE0(this);
    func_00011C20(child);
}
