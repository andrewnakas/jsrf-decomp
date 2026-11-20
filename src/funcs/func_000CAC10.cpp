/* const: 0x40000 */
struct Motion_0005F060;

int func_0005E7B0(void *target, int first, int second, int third, int fourth);
void func_0005EAF0(void *target, Motion_0005F060 *first, float firstTime, Motion_0005F060 *second, float secondTime,
                   Motion_0005F060 *blend, float blendTime);
void func_0005EC20(void *target, int first, int second, int third, int fourth, Motion_0005F060 *blend,
                   float blendTime, float weight);

struct Node {
    virtual ~Node();

    char unknown_04[0x40];
};

struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

// The model at 0x184: its target at 8.
struct Model_000CAD70 {
    char unknown_00[8];
    void *target;
};

struct Body_000CAC10 {
    char unknown_00[0x9c];
    int kind;
};

// The owner at 0x3b4: its body at 4.
struct Owner_000CAC10 {
    char unknown_00[4];
    Body_000CAC10 *body;
};

// The child of Node whose table is at 0x1CE1C8 (destructor func_000C7240).
struct Object_000C7910 : Node, Object_000C60C0 {
    char unknown_048[0x48];
    unsigned int flags;
    char unknown_094[0xf0];
    Model_000CAD70 *model;
    char unknown_188[8];
    int motion;
    Motion_0005F060 *blendMotion;
    Motion_0005F060 *overlay;
    int first;
    int second;
    char unknown_1a4[4];
    int frame;
    float blendFrame;
    float overlayFrame;
    float blend;
    char unknown_1b8[4];
    int state;
    int last;
    int count;
    int changed;
    char unknown_1cc[0x1e8];
    Owner_000CAC10 *owner;
    char unknown_3b8[0x10];
    void (Object_000C7910::**handlers)();

    void func_000CAC10();
};

// Runs the motion state machine unless flag 0x100 is set: a new state at 0x1bc (other than the last at 0x1c0) resets
// the count, frames and blends and marks the change at 0x1c8; then the state's handler from the table at 0x3c8 runs.
// Unless flag 0x40000 is set with the owner's body not of kind 10, the model is posed: the motion at 0x190 (blended
// with 0x194 by func_0005EC20, else func_0005E7B0) on the changed or plain base (0x1a0 or 0x19c), the overlay at 0x198
// on top (func_0005EAF0), and after a change the two bases blended at 0.33.
void Object_000C7910::func_000CAC10()
{
    if (flags & 0x100) {
        return;
    }
    if (state != last) {
        count = 0;
        last = state;
        blendFrame = 0.0f;
        frame = 0;
        blendMotion = 0;
        overlay = 0;
        changed = 1;
    }
    (this->*handlers[state])();
    if ((flags & 0x40000) && owner->body->kind != 10) {
        return;
    }
    int base;
    if (changed) {
        base = second;
    } else {
        base = first;
    }
    if (blendMotion) {
        func_0005EC20(model->target, base, 0, motion, frame, blendMotion, blendFrame, blend);
    } else {
        func_0005E7B0(model->target, base, 0, motion, frame);
    }
    if (overlay) {
        func_0005EAF0(model->target, (Motion_0005F060 *)base, 0.0f, (Motion_0005F060 *)base, 0.0f, overlay,
                      overlayFrame);
    }
    if (changed) {
        func_0005EC20(model->target, first, 0, first, 0, (Motion_0005F060 *)second, 0.0f, 0.33f);
    }
}
