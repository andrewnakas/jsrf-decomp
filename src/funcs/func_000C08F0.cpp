extern "C" void *memset(void *destination, int value, unsigned int size);

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Entry_000C5EA0;

// The target: an owner of the behaviours (only the fields used here).
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    int velocity[3];
    char unknown_5c[0x24];
    Vector3 start;
    int unknown_8c[3];
    int timer;
    char unknown_9c[0x20];
    Entry_000C5EA0 *entry_bc;
    char unknown_c0[4];
    Entry_000C5EA0 *entry_c4;

    Entry_000C5EA0 *func_000C5EA0(unsigned int count);
    int func_000C59E0();
};

// Where the message puts the target: a position and a value (copied as it is, so its type is unknown).
struct Point_000C08F0 {
    Vector3 position;
    int value;
};

struct Message_000C08F0 {
    char unknown_00[0x10];
    Point_000C08F0 *point;
};

struct Object_000C0A20 {
    void func_000C08F0(Object_000C5B50 *target, Message_000C08F0 *message);
};

// Puts the target at the message's point (also its start at 0x80) with the words at 0x50 and 0x8c cleared but for
// the point's value in the second of each, 1 in the timer at 0x98 and the entry for 100 (func_000C5EA0) at 0xbc
// and 0xc4, then func_000C59E0. Does not read `this`.
void Object_000C0A20::func_000C08F0(Object_000C5B50 *target, Message_000C08F0 *message)
{
    Point_000C08F0 *point = message->point;
    target->start = point->position;
    target->position = point->position;
    memset(&target->velocity, 0, sizeof(target->velocity));
    memset(&target->unknown_8c, 0, sizeof(target->unknown_8c));
    int value = point->value;
    target->unknown_8c[1] = value;
    target->velocity[1] = value;
    target->timer = 1;
    Entry_000C5EA0 *entry = target->func_000C5EA0(100);
    target->entry_bc = entry;
    target->entry_c4 = entry;
    target->func_000C59E0();
}
