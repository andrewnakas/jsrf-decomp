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

struct Object_000C1440 {
    int func_000C1450(int current, int target, int step);
};

struct Object_00157F10 : Object_000C1440 {
    void func_000C1F20(Angles_000C1300 *angles, Vector3 *direction, int step);
};

extern Object_00157F10 *data_00257CE8;

// The 15-bit pseudo-random generator.
struct Object_00066980 {
    float func_00066950();
};

struct Object_000C1270 {
    char unknown_00[0x78];
    Object_00066980 *clock;
};

extern Object_000C1270 *data_00257CE4;

float func_0014C820(float value);

// The object a behaviour serves: flags at 0xa4.
struct Object_000C5B50 {
    char unknown_00[0xa4];
    unsigned int flags;
};

// The tuning at 0x30 of the behaviour: a gravity at 0x3c, a distance at 0x44 and a step count at 0x48.
struct Info_000C7910 {
    char unknown_00[0x3c];
    float gravity;
    char unknown_40[4];
    float distance;
    int steps;
};

// The behaviour at 0x3b4: the object it serves at 0x4, its tuning at 0x30.
struct Speed_000C7910 {
    char unknown_00[4];
    Object_000C5B50 *owner;
    char unknown_08[0x28];
    Info_000C7910 *info;
};

// The child of Node whose table is at 0x1CE1C8 (constructor func_000C8680, destructor func_000C7240).
struct Object_000C7910 {
    char unknown_00[0x54];
    Angles_000C1300 angles;
    float speed;
    float base;
    Vector3 target;
    char unknown_74[0x5c];
    Vector3 position;
    char unknown_dc[0xc];
    float lift;
    char unknown_ec[0x2c8];
    Speed_000C7910 *params;

    void func_000C9F10();
};

// Turns towards the target at 0x68 (func_000C1F20; 0x71c a step, 0x2aaa without bit 0x400 of the owner's flags) and
// sets the speed to cover the way in the tuning's step count (with the bit, the target is moved by up to 20 at
// random in x and z and the speed is the distance there; without, the tuning's distance), at most 50/27. The lift is
// half the gravity times the steps above the base at 0x64.
void Object_000C7910::func_000C9F10()
{
    Vector3 to = target;
    Vector3 way;
    if (params->owner->flags & 0x400) {
        to.x += data_00257CE4->clock->func_00066950() * 40.0f - 20.0f;
        to.z += data_00257CE4->clock->func_00066950() * 40.0f - 20.0f;
        way.y = 0;
        way.x = to.x - position.x;
        way.z = to.z - position.z;
        float squared = way.x * way.x + way.z * way.z;
        float distance = func_0014C820(squared);
        speed = distance / params->info->steps;
        data_00257CE8->func_000C1F20(&angles, &way, 0x71c);
    } else {
        way.y = 0;
        way.x = to.x - position.x;
        way.z = to.z - position.z;
        speed = params->info->distance / params->info->steps;
        data_00257CE8->func_000C1F20(&angles, &way, 0x2aaa);
    }
    if (speed > 1.8518518f) {
        speed = 1.8518518f;
    }
    lift = params->info->steps * params->info->gravity * 0.5f + base;
}
