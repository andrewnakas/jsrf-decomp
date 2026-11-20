/* const: 0x10000 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// What a segment sweeps: two counts.
struct Model_000E6720 {
    void *unknown_00;
    unsigned int count;
    char unknown_08[0xc];
    unsigned int otherCount;
    char unknown_18[0xc];
};

// A swept segment (0x44 bytes): from, to and the model to sweep at 0x20.
struct Segment_000E6720 {
    Vector3 from;
    Vector3 to;
    char unknown_18[8];
    Model_000E6720 model;
};

// Where a segment's sweep landed (12 bytes).
struct Result_000E6720 {
    Vector3 point;
};

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[0x60];
    float fall;
    char unknown_64[0x40];
    unsigned int flags;
};

// The class whose table is at 0x1CED80 (handlers at 0x218DD0, run by the state at 0x30).
struct Object_000E5FF0 {
    char unknown_000[4];
    Object_000C5B50 *owner;
    char unknown_008[0x80];
    Segment_000E6720 segments[3];
    Result_000E6720 results[3];

    int func_000E5EA0(Segment_000E6720 *segment, Result_000E6720 *result);
    void func_000E6720();
};

// Sweeps the three segments at 0x88 that have a model to sweep (func_000E5EA0, results at 0x154). On any hit the
// owner stops falling (0x60 = 0, unless it has 0x10000) and loses the flag 0x80; else it falls 0.05 faster, down to
// -25/18, and gets the flag 0x80. Called by slot 1 (func_000E6900).
void Object_000E5FF0::func_000E6720()
{
    int hit = 0;
    if (segments[0].model.count > 0 || segments[0].model.otherCount > 0) {
        hit = func_000E5EA0(&segments[0], &results[0]);
    }
    if (segments[1].model.count > 0 || segments[1].model.otherCount > 0) {
        hit |= func_000E5EA0(&segments[1], &results[1]);
    }
    if (segments[2].model.count > 0 || segments[2].model.otherCount > 0) {
        hit |= func_000E5EA0(&segments[2], &results[2]);
    }
    if (hit) {
        if (!(owner->flags & 0x10000)) {
            owner->fall = 0.0f;
        }
        owner->flags &= ~0x80;
    } else {
        owner->fall -= 0.05f;
        if (owner->fall < -1.3888888f) {
            owner->fall = -1.3888888f;
        }
        owner->flags |= 0x80;
    }
}
