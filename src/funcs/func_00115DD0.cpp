/* sym: ??0Object_00115E20@@QAE@PAUNode@@HIMMMH@Z = 0x00115DD0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_00115E20@@UAE@XZ = 0x00115E20 */
/* sym: ?func_00011C90@Object_00115E20@@UAEXXZ = 0x00115EE0 */
/* sym: ?func_00011C90_2@Object_00115E20@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_4@Object_00115E20@@UAEXXZ = 0x00115E30 */
/* sym: ?func_00011C80_2@Object_00115E20@@UAEXH@Z = 0x00115F40 */
/* sym: ?func_00011C90_6@Object_00115E20@@UAEXXZ = 0x000AECC0 */
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

// The class whose table is at 0x1D3770: overrides slots 1, 7, 9 of Node (its constructor takes three floats and a
// text besides Node's arguments; the one caller, 0x78210, passes 5, 50 and 2); slots 4, 10 hold folded thunks.
struct Object_00115E20 : Node {
    Object_00115E20(Node *owner, int id, unsigned int flags, float first, float second, float step, int text);
    virtual ~Object_00115E20();
    virtual void func_00011C90();
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();

    int text;
    float first;
    float second;
    int value_50;
    char unknown_54[0xc];
    float step;
    char unknown_64[8];
    int state;
    int value_70;
};

Object_00115E20::Object_00115E20(Node *owner, int id, unsigned int flags, float first, float second, float step,
                                 int text)
    : Node(owner, id, flags)
{
    this->first = first;
    this->second = second;
    this->step = step;
    value_50 = 0;
    this->text = text;
    state = 0;
    value_70 = 0;
}
