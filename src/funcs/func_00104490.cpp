/* sym: ??0Object_001044F0@@QAE@PAUNode@@HIH@Z = 0x00104490 */
/* sym: ??1Object_001044F0@@UAE@XZ = 0x001044F0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ?func_00011C90@Object_001044F0@@UAEXXZ = 0x00104500 */
/* sym: ?func_00011C80@Object_001044F0@@UAEXH@Z = 0x001045D0 */
/* sym: ?func_00011C90_2@Object_001044F0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_4@Object_001044F0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_6@Object_001044F0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_8@Object_001044F0@@UAEXXZ = 0x000AECC0 */
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

// The parent it reads two values from (0x16dc and 0x16e0).
struct Parent_00104490 {
    char unknown_0000[0x16dc];
    int value_16dc;
    int value_16e0;
};

// A direct child of Node (table 0x1D1ED8, destructor func_001044F0).
struct Object_001044F0 : Node {
    Object_001044F0(Node *owner, int id, unsigned int flags, int value);
    virtual ~Object_001044F0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();

    int unknown_040;
    int value_44;
    int unknown_048;
    int value_4c;
    int unknown_050;
    int value;
    int unknown_058;
    int unknown_05c;
    float scale;
    int unknown_064;
};

// Keeps the value at 0x54, clears its fields, sets the scale at 0x60 to 1, and takes 0x44 and 0x4c from the
// parent's 0x16dc and 0x16e0.
Object_001044F0::Object_001044F0(Node *owner, int id, unsigned int flags, int value) : Node(owner, id, flags)
{
    this->value = value;
    value_44 = 0;
    unknown_058 = 0;
    unknown_05c = 0;
    unknown_064 = 0;
    unknown_048 = 0;
    scale = 1.0f;
    value_44 = ((Parent_00104490 *)parent)->value_16dc;
    value_4c = ((Parent_00104490 *)parent)->value_16e0;
}
