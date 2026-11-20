/* sym: ?func_00011C90@Object_0006EC00@@UAEXXZ = 0x0006F3A0 */
struct Node {
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
    virtual ~Node();
    virtual void func_00011C90();

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

// A motion: its frame count at +0x2.
struct Motion_0005F060 {
    short unknown_00;
    short frames;
};

// The class whose table is at 0x1CC660 (constructor 0x6F200, destructor 0x6EC00).
struct Object_0006EC00 : Node {
    virtual void func_00011C90();

    char unknown_044[0x58];
    int unknown_9c;
    char unknown_0a0[0x10];
    Motion_0005F060 *motion;
    float time;
    int life;
    char unknown_0bc[0xc];
    int phase;
    int frame;

    void func_0006EE90();
    void func_0006EFF0();
};

// Slot 1: phase 0 starts phase 1 at frame 0; phase 1 runs func_0006EFF0 (or func_0006EE90 while +0x9c is negative)
// and, with a life at +0xb8, takes the object out once the frame count reaches it. Then steps the time of the motion
// at +0xb0, wrapping to 0 at its last frame.
void Object_0006EC00::func_00011C90()
{
    switch (phase) {
    case 0:
        phase = 1;
        frame = 0;
        break;
    case 1:
        if (unknown_9c >= 0) {
            func_0006EFF0();
        } else {
            func_0006EE90();
        }
        if (life >= 0) {
            if (frame >= life) {
                func_00011BE0(this);
                func_00011C20(child);
            }
            frame++;
        }
        break;
    }
    if (motion) {
        time += 1.0f;
        if (time >= motion->frames - 1.0f) {
            time = 0.0f;
        }
    }
}
