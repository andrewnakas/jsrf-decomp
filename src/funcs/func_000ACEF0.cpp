struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000ACFB0;

// A second kind of path the object follows (func_000B4A70 samples it).
struct Object_000B4A70 {
    void func_000B4A70(Object_000ACFB0 *object);
};

// The class whose table is at 0x1CD7B0 (only the fields this method uses).
struct Object_000ACFB0 {
    char unknown_000[0x50];
    Vector3 position;
    char unknown_05c[0x154];
    unsigned int flags;
    char unknown_1b4[8];
    float distance;
    char unknown_1c0[8];
    float speed;
    float length;
    char unknown_1d0[4];
    float fadeIn;
    float fadeOut;
    float fadeStep;
    Vector3 target;

    void func_000AD340();
    void func_000ACEF0(Object_000B4A70 *path);
};

// Samples the path (func_000B4A70); at distance 0 jumps to the target. Moves the distance on by the speed and fades in
// by the step at 0x1dc, past the length at 0x1cc fades out too; once both are full clears the top flag bit; then
// func_000AD340.
void Object_000ACFB0::func_000ACEF0(Object_000B4A70 *path)
{
    path->func_000B4A70(this);
    if (distance == 0.0f) {
        position.x = target.x;
        position.y = target.y;
        position.z = target.z;
    }
    distance += speed;
    float in = fadeIn;
    in += fadeStep;
    fadeIn = in;
    if (distance > length) {
        float out = fadeOut;
        out += fadeStep;
        fadeOut = out;
    }
    if (in >= 1.0f && fadeOut >= 1.0f) {
        flags &= 0x7fffffff;
    }
    func_000AD340();
}
