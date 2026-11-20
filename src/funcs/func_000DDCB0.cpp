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

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 {
    void func_000C1300(Angles_000C1300 *angles, Vector3 *direction);
    void func_000C1530(Vector3 *direction, Angles_000C1300 *angles, int flag);
    void func_000C1F20(Angles_000C1300 *angles, Vector3 *direction, int step);
};

extern Object_00157F10 *data_00257CE8;

// The table of boxes at data_00257CE0.
struct Object_000BFF60 {
    int func_000BFF80(Vector3 *position);
};

extern Object_000BFF60 *data_00257CE0;

float func_0014C820(float value);

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;
    float speed;
    float rise;
    int box;
    char unknown_68[0x3c];
    unsigned int flags;
    Vector3 *next;
};

// The limits at 0x30: the reach at 0x20 and the turn step at 0x4c.
struct Limits_000DDCB0 {
    char unknown_00[0x20];
    float reach;
    char unknown_24[0x28];
    int step;
};

// A point of the route at 0x114 (0x10 bytes).
struct Point_000DDCB0 {
    Vector3 position;
    int unknown_0c;
};

// The base with a pure slot 0 (table 0x1CE304, destructor func_000E7EB0).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600();
};

// The class whose table is at 0x1CE320 (constructor func_000CC620, destructor func_000CC680).
struct Object_000CCE00 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual ~Object_000CCE00();
    virtual void func_000CBCD0();
    virtual void func_000CBD90();
    virtual void func_000CBE60();
    virtual void func_000CBF20();
    virtual void func_000CC910();
    virtual void func_000CD060();
    virtual void func_000CD140();
    virtual void func_000CD1A0();
    virtual void func_000CBF90();
    virtual void func_000CBFC0();
    virtual void func_000CCA40();
    virtual void func_000CC020();

    Object_000C5B50 *owner;
    char unknown_08[0xc];
    Vector3 position;
    char unknown_20[0x10];
    Limits_000DDCB0 *limits;
};

// The class whose table is at 0x1CE7B8 (constructor func_000DCBC0, which runs func_000CC620 first); slots 8 and 16
// stay Object_000CCE00's.
struct Object_000DCBC0 : Object_000CCE00 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000DCBC0();
    virtual void func_000CBCD0();
    virtual void func_000CBD90();
    virtual void func_000CBE60();
    virtual void func_000CC910();
    virtual void func_000CD060();
    virtual void func_000CD140();
    virtual void func_000CD1A0();
    virtual void func_000CBF90();
    virtual void func_000CBFC0();
    virtual void func_000CCA40();

    int func_000DDCB0();

    Vector3 target;
    char unknown_040[0x10];
    Vector3 direction;
    char unknown_05c[4];
    Vector3 last;
    char unknown_06c[0xa4];
    unsigned int count;
    Point_000DDCB0 *points;
    unsigned int index;
};

// Walks the owner toward its next route point on the ground: within the limits' reach of it, moves the owner's next
// point on to the following one at 0x114 (wrapping at the count at 0x110) and returns 0. Otherwise turns the owner's
// angles (with the flag 0x200 toward the direction at 0x34 by func_000C1530, else toward the point by the limits'
// step), steps the position at 0x14 along the heading by the owner's speed and rise, takes the box under it into the
// owner's 0x64 (on a box, keeping the owner's position at 0x60) and the heading at 0x50; returns 1.
int Object_000DCBC0::func_000DDCB0()
{
    Vector3 *next = owner->next;
    Vector3 *at = &position;
    float *speed = &owner->speed;
    Vector3 delta;
    delta.x = next->x - at->x;
    delta.y = 0.0f;
    delta.z = next->z - at->z;
    float length = delta.x * delta.x + delta.z * delta.z;
    float distance = func_0014C820(length);
    if (distance < limits->reach) {
        if (++index >= count) {
            index = 0;
        }
        owner->next = &points[index].position;
        return 0;
    }
    if (owner->flags & 0x200) {
        data_00257CE8->func_000C1530(&target, &owner->angles, 1);
    } else {
        data_00257CE8->func_000C1F20(&owner->angles, &delta, limits->step);
    }
    data_00257CE8->func_000C1300(&owner->angles, &delta);
    at->x += delta.x * *speed;
    at->y += owner->rise;
    at->z += delta.z * *speed;
    owner->box = data_00257CE0->func_000BFF80(at);
    if (owner->box >= 0) {
        last = owner->position;
    }
    direction = delta;
    return 1;
}
