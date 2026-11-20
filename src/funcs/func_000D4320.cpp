struct Vector3 {
    float x;
    float y;
    float z;
};

void func_000C6950(void *place, float *scale);

struct Owner_000D1700 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0xc];
    float speed;
    float climb;
    char unknown_64[0x40];
    unsigned int flags;
};

struct Object_000D1700 {
    char unknown_000[4];
    Owner_000D1700 *owner;
    int state;
    char unknown_00c[4];
    int timer;
    char unknown_014[4];
    float y;
    char unknown_01c[0x24];
    float scale[11];
    int placed;
    char unknown_070[0xec0];
    int next;
    char unknown_f34[4];
    int phase;

    void func_000D38D0(int kind);
    void func_000D4320();
};

// Entry 23 of the member-function table at 0x2169e0: climbs by the owner's 0x60 and runs func_000D38D0(3); in phase 2
// at 0xf38, when the owner lacks the flag 0x80: state 0x18, 0xf30 = 0x13, the owner gains the flag 0x8000 and stops,
// the timer restarts, and the first time func_000C6950 places the owner's position with the scale at 0x40.
void Object_000D1700::func_000D4320()
{
    y += owner->climb;
    func_000D38D0(3);
    if (phase == 2 && !(owner->flags & 0x80)) {
        state = 0x18;
        next = 0x13;
        owner->flags |= 0x8000;
        owner->speed = 0.0f;
        timer = 0;
        if (placed == 0) {
            func_000C6950(&owner->position, scale);
            placed = 1;
        }
    }
}
