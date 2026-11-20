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

// The object at data_00257CE8 (func_00157F10 is the engine's); it also answers func_000C1450.
struct Object_00157F10 : Object_000C1440 {
    void func_000C1F20(Angles_000C1300 *angles, Vector3 *direction, int step);
};

extern Object_00157F10 *data_00257CE8;

// The object in data_00257CE4: its point at 0x7c.
struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 point;
};

extern Object_000C1270 *data_00257CE4;

// The object the behaviour serves: its angles at 0x50, its flags at 0xa4.
struct Object_000C5B50 {
    char unknown_00[0x50];
    Angles_000C1300 angles;
    char unknown_5c[0x48];
    unsigned int flags;
};

// The behaviour's tuning: the turn step at 0x4c.
struct Info_000C7910 {
    char unknown_00[0x4c];
    int turn;
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
    char unknown_00[0x48];
    Vector3 position;
    Angles_000C1300 angles;
    char unknown_60[0x30];
    unsigned int flags;
    char unknown_94[0xb4];
    int heading;
    char unknown_14c[0x268];
    Speed_000C7910 *speed;

    void func_000C9D70();
};

// Keeps the heading (angles.y) at 0x148. Unless it or the object its behaviour serves has flag 2, turns the angles
// at 0x54 toward that object's (func_000C1450, by the tuning's step); otherwise toward the point of data_00257CE4
// (func_000C1F20).
void Object_000C7910::func_000C9D70()
{
    Angles_000C1300 *turned = &angles;
    heading = turned->y;
    if (!(flags & 2) && !(speed->owner->flags & 2)) {
        turned->x = data_00257CE8->func_000C1450(turned->x, speed->owner->angles.x, speed->info->turn);
        turned->y = data_00257CE8->func_000C1450(turned->y, speed->owner->angles.y, speed->info->turn);
        return;
    }
    Vector3 direction;
    direction.x = data_00257CE4->point.x - position.x;
    direction.y = data_00257CE4->point.y - position.y;
    direction.z = data_00257CE4->point.z - position.z;
    data_00257CE8->func_000C1F20(turned, &direction, speed->info->turn);
}
