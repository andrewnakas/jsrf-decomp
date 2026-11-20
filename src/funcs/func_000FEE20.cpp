/* sym: ??0Object_0010E2C0@@QAE@PAUNode@@HIHH@Z = 0x0010E120 */
/* sym: ??0Object_0011AC40@@QAE@PAUNode@@HI@Z = 0x0011B450 */
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

// The camera node (constructor func_00012170).
struct Object_00012170 : Node {
    char unknown_040[0x58];
};

// Object 0x1163 (constructor func_000FF230, destructor func_000FEC60).
struct Object_000FEDB0 : Object_00012170 {
    void func_000FEE20(int kind, int first, int second, int third);
};

// The class whose table is at 0x1D23B0 (destructor func_0010E2C0).
struct Object_0010E2C0 {
    Object_0010E2C0(Node *owner, int id, unsigned int flags, int first, int second);

    char unknown_00[0xb8];
};

// The class whose table is at 0x1D7D00 (destructor func_0011AC40).
struct Object_0011AC40 {
    Object_0011AC40(Node *owner, int id, unsigned int flags);

    char unknown_000[0x434];
};

void func_00075DE0(Node *owner, int value);

// Creates the child for `kind` under itself (id -1, flags 0x100): 0 an Object_0010E2C0, 1 an Object_0011AC40;
// 2 calls func_00075DE0(0, 0). The other arguments are not read.
void Object_000FEDB0::func_000FEE20(int kind, int, int, int)
{
    switch (kind) {
    case 0:
        new Object_0010E2C0(this, -1, 0x100, 0, 0);
        break;
    case 1:
        new Object_0011AC40(this, -1, 0x100);
        break;
    case 2:
        func_00075DE0(0, 0);
        break;
    }
}
