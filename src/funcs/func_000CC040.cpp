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
    void func_000C1F20(Angles_000C1300 *angles, Vector3 *direction, int step);
};

extern Object_00157F10 *data_00257CE8;

// The table of boxes at data_00257CE0.
struct Object_000BFF60 {
    int func_000BFF80(Vector3 *position);
};

extern Object_000BFF60 *data_00257CE0;

// A stop of a route: its box (negative at the end), its point, its kind and the next stop.
struct Route_000CC040 {
    int box;
    Vector3 *point;
    int kind;
    Route_000CC040 *next;
};

// The owner at 0x4: its position at 0x44, angles at 0x50, speed at 0x5c, rise at 0x60, box at 0x64 and its route at
// 0xbc.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;
    float speed;
    float rise;
    int box;
    char unknown_68[0x54];
    Route_000CC040 *route;
};

struct Limits_000CC020 {
    char unknown_00[0x4c];
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

    int func_000CC040();

    Object_000C5B50 *owner;
    char unknown_08[0xc];
    Vector3 position;
    char unknown_20[0x10];
    Limits_000CC020 *limits;
    char unknown_34[0x1c];
    Vector3 direction;
    char unknown_5c[4];
    Vector3 last;
};

// Follows the owner's route; 0 at its end. Turns the owner's angles toward the stop's point on the flat (the limits'
// step, func_000C1F20), steps the position at 0x14 along the new heading (func_000C1300) by the owner's speed and
// rise, keeps the heading at 0x50 and, on a box (func_000BFF80), the owner's position at 0x60. Within one step of the
// point the owner takes the stop's box and moves on to the next stop (its speed cleared when that one ends the
// route); then 0 when that stop is of kind 4 or the one after it ends the route. Otherwise 1.
int Object_000CCE00::func_000CC040()
{
    Object_000C5B50 *owner = this->owner;
    Route_000CC040 *route = owner->route;
    Vector3 *point = route->point;
    if (route->box < 0) {
        return 0;
    }
    Vector3 delta;
    delta.x = point->x - position.x;
    delta.y = 0.0f;
    delta.z = point->z - position.z;
    data_00257CE8->func_000C1F20(&owner->angles, &delta, limits->step);
    float distance = delta.x * delta.x + delta.z * delta.z;
    data_00257CE8->func_000C1300(&this->owner->angles, &delta);
    Vector3 *at = &position;
    at->x += delta.x * owner->speed;
    at->y += this->owner->rise;
    at->z += delta.z * owner->speed;
    direction = delta;
    if (data_00257CE0->func_000BFF80(&this->owner->position) >= 0) {
        last = this->owner->position;
    }
    if (owner->speed * owner->speed >= distance) {
        this->owner->box = route->box;
        this->owner->route = route->next;
        if (this->owner->route->box < 0) {
            owner->speed = 0.0f;
        }
        if (this->owner->route->kind == 4 || this->owner->route->next->box < 0) {
            return 0;
        }
    }
    return 1;
}
