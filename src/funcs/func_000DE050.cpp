struct Owner_000DCBC0 {
    char unknown_00[0x5c];
    float speed;
    float climb;
    char unknown_64[0x40];
    unsigned int flags;
};

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000DCBC0 {
    char unknown_000[0x4];
    Owner_000DCBC0 *owner;
    int state;
    char unknown_00c[0x4];
    int count;
    Vector3 position;
    char unknown_020[0x104];
    float direction[3];
    char unknown_130[0x98];
    int phase;

    void func_000DE050();
};

// A handler of the table at 0x217A20: moves the position at 0x14 along the direction at 0x124 by the owner's speed
// and lifts it by the owner's climb; in phase 2 moves to state 19, sets flag 0x8000 on the owner, clears the count at
// 0x10 and stops the owner.
void Object_000DCBC0::func_000DE050()
{
    position.x += direction[0] * owner->speed;
    position.y += owner->climb;
    position.z += direction[2] * owner->speed;
    if (phase == 2) {
        state = 19;
        owner->flags |= 0x8000;
        count = 0;
        owner->speed = 0.0f;
    }
}
