extern "C" void *memset(void *destination, int value, unsigned int size);

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
    void func_000C1F20(Angles_000C1300 *angles, Vector3 *direction, int step);
};

extern Object_00157F10 *data_00257CE8;

void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *a, const Vector3 *b);

// The target: an owner of the behaviours (only the fields used here).
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;
    char unknown_5c[0x24];
    Vector3 start;
    Angles_000C1300 startAngles;
    int timer;
};

// Where the message puts the target: a position and the point it faces.
struct Point_000C0980 {
    Vector3 position;
    Vector3 target;
};

struct Message_000C0980 {
    char unknown_00[0x10];
    Point_000C0980 *point;
};

struct Object_000C0A20 {
    void func_000C0980(Object_000C5B50 *target, Message_000C0980 *message);
};

// Puts the target at the message's point (also its start at 0x80) with 1 in the timer at 0x98, turned (func_000C1F20,
// step 0x8000, from cleared angles at 0x50) toward the point it faces; the turn's x is cleared and the angles are also
// kept at 0x8c. Does not read `this`.
void Object_000C0A20::func_000C0980(Object_000C5B50 *target, Message_000C0980 *message)
{
    Point_000C0980 *point = message->point;
    target->timer = 1;
    target->start = point->position;
    target->position = point->position;
    Vector3 direction;
    func_0014C4C0(&direction, &point->target, &point->position);
    Angles_000C1300 *angles = &target->angles;
    memset(angles, 0, sizeof(*angles));
    data_00257CE8->func_000C1F20(angles, &direction, 0x8000);
    angles->x = 0;
    target->startAngles = target->angles;
}
