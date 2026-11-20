void func_000C6950(void *place, float *scale);

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Owner_000DCBC0 {
    char unknown_00[0x44];
    char place[0x18];
    float speed;
    float climb;
    char unknown_64[0x40];
    unsigned int flags;
};

struct Object_000DCBC0 {
    char unknown_000[0x4];
    Owner_000DCBC0 *owner;
    int state;
    char unknown_00c[0x8];
    Vector3 position;
    char unknown_020[0x104];
    float direction[3];
    char unknown_130[0x30];
    int placed;
    char unknown_164[0x5c];
    int next;
    char unknown_1c4[0x4];
    int phase;

    void func_000DE2F0();
};

// A handler of the table at 0x217A20: moves the position at 0x14 along the direction at 0x124 by the owner's speed
// and lifts it by the owner's climb; in phase 2, unless the owner has flag 0x80, moves to state 29 with 20 at 0x1c0,
// sets flag 0x8000 on the owner, stops it and, once, places it (func_000C6950 with the direction).
void Object_000DCBC0::func_000DE2F0()
{
    Owner_000DCBC0 *current = owner;
    position.x += owner->speed * direction[0];
    position.y += current->climb;
    position.z += direction[2] * current->speed;
    if (phase == 2 && !(current->flags & 0x80)) {
        state = 29;
        next = 20;
        current->flags |= 0x8000;
        owner->speed = 0.0f;
        if (!placed) {
            func_000C6950(owner->place, direction);
            placed = 1;
        }
    }
}
