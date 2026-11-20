struct Vector3 {
    float x;
    float y;
    float z;
};

struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

struct Object_00157F10 {
    void func_000C1300(Angles_000C1300 *angles, Vector3 *direction);
    void func_000C1530(Vector3 *direction, Angles_000C1300 *angles, int flag);
    void func_000C1F20(Angles_000C1300 *angles, Vector3 *direction, int step);
};

extern Object_00157F10 *data_00257CE8;

// The owner at 0x4: angles at 0x50, speed at 0x5c, rise at 0x60, flags at 0xa4 and the next point at 0xa8.
struct Object_000C5B50 {
    char unknown_00[0x50];
    Angles_000C1300 angles;
    float speed;
    float rise;
    char unknown_64[0x40];
    unsigned int flags;
    Vector3 *next;
};

struct Limits_000CC020 {
    char unknown_00[4];
    float limit;
    char unknown_08[0x44];
    int step;
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

    void func_000CC4B0(float value);
    void func_000CCD10();

    Object_000C5B50 *owner;
    char unknown_08[0xc];
    Vector3 position;
    char unknown_20[0x10];
    Limits_000CC020 *limits;
    Vector3 target;
    char unknown_40[0x10];
    Vector3 direction;
};

// Heads the owner for its next point on the ground: func_000CC4B0 with the limits' value at 4, then turns the
// owner's angles (with the flag 0x200 toward the direction at 0x34 by func_000C1530, else toward the point by the
// limits' step at 0x4c), steps the position at 0x14 along the new heading by the owner's speed and rise, and keeps
// the heading at 0x50.
void Object_000CCE00::func_000CCD10()
{
    Vector3 *next = owner->next;
    float *speed = &owner->speed;
    Vector3 delta;
    delta.x = next->x - position.x;
    delta.y = 0.0f;
    delta.z = next->z - position.z;
    func_000CC4B0(limits->limit);
    if (owner->flags & 0x200) {
        data_00257CE8->func_000C1530(&target, &owner->angles, 1);
    } else {
        data_00257CE8->func_000C1F20(&owner->angles, &delta, limits->step);
    }
    data_00257CE8->func_000C1300(&owner->angles, &delta);
    Vector3 moved;
    moved.x = delta.x * *speed + position.x;
    moved.y = owner->rise + position.y;
    moved.z = delta.z * *speed + position.z;
    position = moved;
    direction = delta;
}
