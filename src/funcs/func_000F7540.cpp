/* sym: ?func_00011C90@Object_000F7990@@UAEXXZ = 0x000F7540 */
unsigned int func_0014C690(float value);

struct Node {
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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

// One corner of the two quads (0x18 bytes).
struct Corner_000F7990 {
    float x;
    float y;
    unsigned int color;
    unsigned int specular;
    float u;
    float v;
};

// A direct child of Node (object 0x1164, table 0x1CF338, destructor func_000F74E0) that holds a resource at 0x48.
struct Object_000F7990 : Node {
    virtual void func_00011C90();

    char unknown_040[4];
    unsigned int argument;
    void *resource;
    Corner_000F7990 first[4];
    Corner_000F7990 second[4];
    int mode_10c;
    int mode_110;
    unsigned int state;
    int unknown_118;
    float step;
    float scale;
    float target;
    float value;
    float fade;
};

// Slot 1 (the step). State 0 goes to 1; state 1, once the mode at 0x10c differs from 0x110, moves to state 2 with
// the bar's target 0, 100 or 240 for modes 0 to 2 and the step from the y of the first quad's third corner to it over
// the scale at 0x120 (other modes just take the new mode). State 2 moves the inner edges of the two quads by the step
// until they reach the target, then fixes them (and 480 less it), takes the new mode and state 1 or 3 by the top bit
// of 0x44; and sets the alpha of all eight corners from the fade at 0x12c. State 3 unlinks the node (func_00011BE0,
// func_00011C20 on its child).
void Object_000F7990::func_00011C90()
{
    switch (state) {
    case 0:
        state = 1;
        return;
    case 1:
        if (mode_10c == mode_110) {
            return;
        }
        state = 2;
        switch (mode_10c) {
        case 0:
            target = 0.0f;
            step = first[2].y / scale;
            return;
        case 1:
            target = 100.0f;
            step = (first[2].y - 100.0f) / scale;
            return;
        case 2:
            target = 240.0f;
            step = (first[2].y - 240.0f) / scale;
            return;
        default:
            state = 1;
            mode_110 = mode_10c;
            return;
        }
    case 2: {
        first[2].y -= step;
        first[3].y -= step;
        second[0].y += step;
        second[1].y += step;
        if (step < 0.0f) {
            if (!(first[2].y >= target)) {
                goto colors;
            }
        } else if (!(first[2].y <= target)) {
            goto colors;
        }
        first[2].y = target;
        second[1].y = second[0].y = 480.0f - target;
        first[3].y = target;
        state = (argument | 0x40000000) >> 30;
        mode_110 = mode_10c;
    colors:
        unsigned int color = func_0014C690(fade * 255.0f) << 24;
        for (int i = 0; i < 4; i++) {
            first[i].color = color;
            second[i].color = color;
        }
        return;
    }
    case 3:
        func_00011BE0(this);
        func_00011C20(child);
        return;
    }
}
