extern "C" void *memset(void *destination, int value, unsigned int size);

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Target_000C0880 {
    char unknown_00[0x44];
    Vector3 position;
    Vector3 velocity;
    char unknown_5c[0x24];
    Vector3 start;
    Vector3 unknown_8c;
    int timer;
};

struct Message_000C0880 {
    char unknown_00[0x10];
    Vector3 *position;
};

struct Object_000C0A20 {
    void func_000C0880(Target_000C0880 *target, Message_000C0880 *message);
};

// Puts the target at the message's position (also its start at 0x80) with the vectors at 0x50 and 0x8c cleared
// and 1 in the timer at 0x98. Does not read `this` (`ret 8`).
void Object_000C0A20::func_000C0880(Target_000C0880 *target, Message_000C0880 *message)
{
    Vector3 *position = message->position;
    target->timer = 1;
    target->start = *position;
    target->position = *position;
    memset(&target->velocity, 0, sizeof(target->velocity));
    memset(&target->unknown_8c, 0, sizeof(target->unknown_8c));
}
