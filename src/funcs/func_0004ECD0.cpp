/* sym: ??1Object_0004EF90@@UAE@XZ = 0x0004EF00 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_0004EF90@@UAEXXZ = 0x0004EF90 */
/* sym: ?func_00011C80@Object_0004EF90@@UAEXH@Z = 0x0004F9A0 */
/* sym: ?func_00011C90_2@Object_0004EF90@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_4@Object_0004EF90@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_6@Object_0004EF90@@UAEXXZ = 0x000AECC0 */
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

struct Game {
    int func_000127E0(int index);
    void func_000127C0(int index, int value);
};

extern Game *data_0022FCE0;

/* sym: ??0Object_000A8360@@QAE@PAUNode@@HI@Z = 0x000A82D0 */
/* sym: ??0Object_0003E420@@QAE@PAUNode@@HI@Z = 0x0003E5F0 */
/* sym: ??0Object_00060650@@QAE@PAUNode@@HIH@Z = 0x000605B0 */
/* sym: ??0Object_000FDF30@@QAE@PAUNode@@HI@Z = 0x000FE740 */
/* sym: ??0Object_000FEDB0@@QAE@PAUNode@@HI@Z = 0x000FF230 */
/* sym: ??0Object_000C0A90@@QAE@PAUNode@@HI@Z = 0x000C0A90 */
/* sym: ??0Object_00117A30@@QAE@PAUNode@@HI@Z = 0x001179F0 */
/* sym: ??0Object_00117510@@QAE@PAUNode@@HI@Z = 0x001174D0 */
/* sym: ??0Object_0004EF90@@QAE@PAUNode@@HI@Z = 0x0004ECD0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* const: 0x20000 */
/* const: 0x10003 */

// The children the constructor creates; only their constructors and sizes matter here.
struct Object_000A8360 : Node {
    Object_000A8360(Node *owner, int id, unsigned int flags);
    char unknown_44[0x1280];
};

struct Object_0003E420 : Node {
    Object_0003E420(Node *owner, int id, unsigned int flags);
    char unknown_44[0x24];
};

struct Object_00060650 : Node {
    Object_00060650(Node *owner, int id, unsigned int flags, int unused);
    char unknown_44[0xc];
};

struct Object_000FDF30 : Node {
    Object_000FDF30(Node *owner, int id, unsigned int flags);
    char unknown_44[0x300];
};

struct Object_000FEDB0 : Node {
    Object_000FEDB0(Node *owner, int id, unsigned int flags);
    char unknown_44[0xd0c];
};

struct Object_000C0A90 : Node {
    Object_000C0A90(Node *owner, int id, unsigned int flags);
    char unknown_44[0xc];
};

struct Object_00117A30 : Node {
    Object_00117A30(Node *owner, int id, unsigned int flags);
    char unknown_44[0x20c];
};

struct Object_00117510 : Node {
    Object_00117510(Node *owner, int id, unsigned int flags);
    char unknown_44[0x3cc];
};

// The class whose table is at 0x1CAAF8: overrides slots 1 (4EF90), 3 (4F9A0), 4 (AECC0), 7 (AECC0), 10 (AECC0).
struct Object_0004EF90 : Node {
    virtual ~Object_0004EF90();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();

    Object_0004EF90(Node *owner, int id, unsigned int flags);

    unsigned int state;
    void *unknown_48;
    int unknown_4c;
    int unknown_50;
    char unknown_54[0x3c];
    void *buffers[4];
};

// Creates the eight children, picks the state from game setting 0xb and clears the four buffers and settings 0x14d to
// 0x150.
Object_0004EF90::Object_0004EF90(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
{
    this->flags |= 0x20000;
    unknown_4c = 0;
    new Object_000A8360(this, 0xb, 0);
    new Object_0003E420(this, 0xe7, 0);
    new Object_00060650(this, 0xe8, 0x20, 1);
    new Object_000FDF30(this, 0x1165, 0x10003);
    new Object_000FEDB0(this, 0x1163, 0x10003);
    new Object_000C0A90(this, 0x12b1, 0);
    new Object_00117A30(this, 0xe9, 0);
    new Object_00117510(this, 0xea, 0);
    unknown_50 = 9;
    switch (data_0022FCE0->func_000127E0(0xb)) {
    case 0:
        state = 0;
        break;
    case 1:
        state = 0x12;
        break;
    case 2:
        state = 0xa;
        break;
    }
    unknown_48 = 0;
    for (unsigned int i = 0; i < 4; i++) {
        buffers[i] = 0;
        data_0022FCE0->func_000127C0(i + 0x14d, 0);
    }
}
