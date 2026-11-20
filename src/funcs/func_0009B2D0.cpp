struct Node {
    virtual ~Node();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(int argument);

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

    Node *func_00011BD0();
};

struct Owner_0009B2D0 {
    char unknown_000[0x8b8];
    int index;
};

extern int data_0020E6D0[];

struct Object_000A1C50 : Node {
    char unknown_040[0xdc];
    int value_11c;
    char unknown_120[0x8ec];
    int value_a0c;
    char unknown_a10[0x2b0];
    int value_cc0;
    char unknown_cc4[8];
    int value_ccc;
    char unknown_cd0[0x13c];
    int value_e0c;
    char unknown_e10[0x40];
    int state_e50;
    char unknown_e54[4];
    int phase_e58;
    char unknown_e5c[0x10];
    int value_e6c;

    void func_0009B2D0();
};

// Enters state 23: takes the field at 0x11c from the table data_0020E6D0 by the parent's index at
// 0x8b8, copies the field at 0xe0c to 0xcc0 and 0xccc, and sets the phase at 0xe58 to 12.
void Object_000A1C50::func_0009B2D0()
{
    state_e50 = 23;
    value_11c = data_0020E6D0[((Owner_0009B2D0 *)func_00011BD0())->index];
    value_e6c = 0;
    value_a0c = 1;
    value_cc0 = value_e0c;
    value_ccc = value_e0c;
    phase_e58 = 12;
}
