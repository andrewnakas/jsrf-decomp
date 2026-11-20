struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000ACFB0;

// The path the object follows (func_000B45A0 samples it).
struct Object_000B45A0 {
    void func_000B46E0(Object_000ACFB0 *object);
};

// The class whose table is at 0x1CD7B0 (only the fields this method uses).
struct Object_000ACFB0 {
    char unknown_000[0x80];
    float step;
    char unknown_084[0x12c];
    unsigned int flags;
    char unknown_1b4[8];
    float distance;
    char unknown_1c0[8];
    float speed;
    char unknown_1cc[0x44];
    int angle;

    void func_000ACDB0(Object_000B45A0 *path);
};

// Follows the path (func_000B46E0) slowing by the step at 0x80: while both stay above 0 the angle at 0x210 turns down
// by 0x5b to -0x222, otherwise the speed stops and the angle comes back up by 0x24 to 0 (then bit 30 of the flags
// clears). The distance moves on by the speed.
void Object_000ACFB0::func_000ACDB0(Object_000B45A0 *path)
{
    path->func_000B46E0(this);
    speed -= step;
    if (speed > 0.0f && step > 0.0f) {
        angle -= 0x5b;
        if (angle <= -0x222) {
            angle = -0x222;
        }
    } else {
        speed = 0.0f;
        angle += 0x24;
        if (angle >= 0) {
            angle = 0;
            flags &= ~0x40000000;
        }
    }
    distance += speed;
}
