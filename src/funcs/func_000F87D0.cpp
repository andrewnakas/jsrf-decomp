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


struct Object_00043700 {
    int func_00043700();
};

extern Object_00043700 data_001FC724;

int func_000FE650(int row, int column);

// The parent: its row of object 0x1165's table is at 0x7c.
struct Parent_000F87D0 : Node {
    char unknown_040[0x3c];
    int row;
};

// The class whose slot 3 is func_000F8130 (table built by func_000F80C0).
struct Object_000F96A0 : Node {
    int func_000F87D0(int column, char *out);
};

// Called by func_000F9090: writes entry [row][column] of object 0x1165's table (func_000FE650; the row is the
// parent's 0x7c) in decimal to out, after a sign (5, 0xb, or '-' in ASCII) when it is negative; each digit as a
// full-width two-byte character, or as an ASCII digit when func_00043700 of data_001FC724 is not 0. Gives the bytes
// written.
int Object_000F96A0::func_000F87D0(int column, char *out)
{
    Parent_000F87D0 *owner = (Parent_000F87D0 *)parent;
    int digits[10];
    int count = 0;
    int length = 0;
    int ascii = data_001FC724.func_00043700();
    int value = func_000FE650(owner->row, column);
    if (value < 0) {
        if (!ascii) {
            out[0] = 5;
            out[1] = 0xb;
            length = 2;
        } else {
            out[0] = '-';
            length = 1;
        }
    }
    while (value != 0) {
        digits[count++] = value % 10;
        value /= 10;
    }
    if (count == 0) {
        digits[0] = 0;
        count = 1;
    }
    for (int i = count - 1; i >= 0; i--) {
        if (!ascii) {
            unsigned short c = (char)digits[i] + 0x824f;
            out[length++] = c >> 8;
            out[length++] = (char)c;
        } else {
            out[length++] = digits[i] + '0';
        }
    }
    return length;
}
