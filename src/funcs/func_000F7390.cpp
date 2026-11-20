/* sym: ?func_00011C90@Object_000F7280@@UAEXXZ = 0x000F7390 */
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

// The child of Node whose table is at 0x1CF2F8 (constructor func_000F7280, destructor func_000F7320).
struct Object_000F7280 : Node {
    virtual void func_00011C90();

    char unknown_040[8];
    short *range;
    float time;
};

// Slot 1: with a range at 0x48, counts the time at 0x4c up by 1 and wraps it to 0 at the second short of the range,
// less 1.
void Object_000F7280::func_00011C90()
{
    if (range) {
        time += 1.0f;
        if (time >= range[1] - 1.0f) {
            time = 0.0f;
        }
    }
}
