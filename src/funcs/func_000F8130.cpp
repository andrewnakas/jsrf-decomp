/* sym: ?func_00011C80@Object_000F96A0@@UAEXH@Z = 0x000F8130 */
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

// An entry of the buffer at 0x50 (0x114 bytes): its height at +0x110.
struct Entry_000F8130 {
    char unknown_000[0x110];
    float height;
};

// The child of Node whose table is at 0x1D07B0 (constructor func_000F96A0, destructor func_000F80C0).
struct Object_000F96A0 : Node {
    virtual void func_00011C80(int argument);

    char unknown_040[8];
    unsigned int flags_48;
    void *first;
    Entry_000F8130 *entries;
    char text[0x108];
    int index;
    char unknown_160[0x10];
    unsigned int state;
    char unknown_174[8];
    unsigned int color;
    char unknown_180[0x10];
    float x;
    float y;
    char unknown_198[4];
    unsigned int alpha;
};

void func_0003D5D0(float x, float y, float scale, unsigned int color, float first, float second, int text);

// Slot 3: in states 2 to 7, draws the text at 0x54 (func_0003D5D0) at x and, with flag bit 30 at 0x48, the height of
// entry `index` of the buffer at 0x50, else the y at 0x194; scale 1.1, the colour at 0x17c with the alpha at 0x19c.
// The argument is not read.
void Object_000F96A0::func_00011C80(int)
{
    if (state >= 2 && state <= 7) {
        unsigned int value = (alpha << 24) | color;
        if ((flags_48 & 0x40000000) == 0) {
            func_0003D5D0(x, y, 1.1f, value, 1.0f, 1.0f, (int)text);
        } else {
            func_0003D5D0(x, entries[index].height, 1.1f, value, 1.0f, 1.0f, (int)text);
        }
    }
}
