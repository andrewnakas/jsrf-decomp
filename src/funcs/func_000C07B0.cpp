struct Vector3 {
    float x;
    float y;
    float z;
};

struct Entry_000C5EA0;

// Three angles (x, y, z).
struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

// The target: an owner of the behaviours (only the fields used here).
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;
    char unknown_5c[0x24];
    Vector3 start;
    Angles_000C1300 startAngles;
    int timer;
    char unknown_9c[8];
    unsigned int flags;
    char unknown_a8[0x14];
    Entry_000C5EA0 *entry_bc;
    char unknown_c0[4];
    Entry_000C5EA0 *entry_c4;

    Entry_000C5EA0 *func_000C5EA0(unsigned int count);
    int func_000C59E0();
};

// Where the message puts the target: a position, angles and a count.
struct Point_000C07B0 {
    Vector3 position;
    Angles_000C1300 angles;
    unsigned int count;
};

struct Message_000C07B0 {
    char unknown_00[0x10];
    Point_000C07B0 *point;
};

struct Object_000C0A20 {
    void func_000C07B0(Object_000C5B50 *target, Message_000C07B0 *message);
};

// Puts the target at the message's point and angles (also its start at 0x80 and 0x8c) with the point's count, at
// most 5, in the timer at 0x98 (a count of 0 or less gives 0 and flag 0x20 at 0xa4), the entry for 100
// (func_000C5EA0) at 0xbc and 0xc4, then func_000C59E0. Does not read `this`.
void Object_000C0A20::func_000C07B0(Object_000C5B50 *target, Message_000C07B0 *message)
{
    Point_000C07B0 *point = message->point;
    target->start = point->position;
    target->position = point->position;
    target->angles = point->angles;
    target->startAngles = point->angles;
    unsigned int count = point->count;
    target->timer = count;
    if (count > 5) {
        target->timer = 5;
    } else if (target->timer <= 0) {
        target->timer = 0;
        target->flags |= 0x20;
    }
    Entry_000C5EA0 *entry = target->func_000C5EA0(100);
    target->entry_bc = entry;
    target->entry_c4 = entry;
    target->func_000C59E0();
}
