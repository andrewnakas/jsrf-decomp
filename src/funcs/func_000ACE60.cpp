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
    char unknown_000[0x50];
    Vector3 position;
    char unknown_05c[0x148];
    float limit;
    char unknown_1a8[8];
    unsigned int flags;
    char unknown_1b4[8];
    float distance;
    char unknown_1c0[8];
    float speed;
    char unknown_1cc[0x14];
    Vector3 target;

    void func_000AD340();
    void func_000ACE60(Object_000B45A0 *path);
};

void Object_000ACFB0::func_000ACE60(Object_000B45A0 *path)
{
    path->func_000B46E0(this);
    if (distance == 0.0f) {
        position.x = target.x;
        position.y = target.y;
        position.z = target.z;
    }
    speed += 0.02f;
    if (speed >= limit) {
        speed = limit;
        flags &= ~0x8000000;
    }
    distance += speed;
    func_000AD340();
}
