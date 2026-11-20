/* sym: ?func_00011C90@Object_000F7E80@@UAEXXZ = 0x000F7E90 */
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

// A direct child of Node (destructor func_000F7E80).
struct Object_000F7E80 : Node {
    virtual void func_00011C90();

    char unknown_040[0x5c];
    short *range;
    float time;
    int unknown_a4;
    int phase;
};

// Slot 1: the first time, starts the time at 0; then, with a motion range at 0x9c, steps the time by 1 and wraps
// it to 0 past the range's frame count (its second short) minus 1.
void Object_000F7E80::func_00011C90()
{
    switch (phase) {
    case 0:
        time = 0.0f;
        phase = 1;
    case 1:
        if (range) {
            time += 1.0f;
            if (time > range[1] - 1.0f) {
                time = 0.0f;
            }
        }
    }
}
