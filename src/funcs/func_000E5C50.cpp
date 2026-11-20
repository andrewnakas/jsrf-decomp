struct Vector3 {
    float x;
    float y;
    float z;
};

// Three angles (x, y, z).
struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

// The object in data_00257CE8.
struct Object_00157F10 {
    void func_000C1F20(Angles_000C1300 *angles, Vector3 *direction, int step);
};

extern Object_00157F10 *data_00257CE8;

struct Owner_000E5C50 {
    char unknown_00[0x5c];
    float speed;
    float rate;
};

struct Object_000E6590 {
    char unknown_00[4];
    Owner_000E5C50 *owner;
    int state;
    char unknown_0c[0x24];
    int value_30;
    int value_34;
    char unknown_38[4];
    int heading;
    Vector3 direction;

    void func_000E5C50(int argument);
};

// Below a speed of 1.1574 cuts the owner's speed (+0x5c) to 0.7 of itself with rate 25/27 (+0x60), else to 0.8
// with rate 25/18; then state 0xe, +0x30 = 0xb, +0x34 = 0, and the heading at +0x3c turned fully (0x8000) toward
// the direction at +0x40 (func_000C1F20). The argument is not read.
void Object_000E6590::func_000E5C50(int)
{
    if (owner->speed < 1.1574074f) {
        owner->speed *= 0.7f;
        owner->rate = 0.9259259f;
    } else {
        owner->speed *= 0.8f;
        owner->rate = 1.3888888f;
    }
    state = 0xe;
    value_30 = 0xb;
    value_34 = 0;
    Angles_000C1300 angles;
    data_00257CE8->func_000C1F20(&angles, &direction, 0x8000);
    heading = angles.y;
}
