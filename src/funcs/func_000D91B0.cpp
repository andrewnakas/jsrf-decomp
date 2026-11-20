void func_000C6950(void *place, float *scale);

struct Owner_000D91B0 {
    char unknown_00[0x44];
    char place[0x18];
    int value_5c;
    float step;
    char unknown_64[0x40];
    unsigned int flags;
};

struct Object_000D8A40 {
    char unknown_000[0x4];
    Owner_000D91B0 *owner;
    int state;
    char unknown_00c[0xc];
    float distance;
    char unknown_01c[0x3c];
    float scale[11];
    int placed;
    char unknown_088[0x58];
    int next;
    char unknown_0e4[0x4];
    int phase;

    void func_000D91B0();
};

// A handler of the table at 0x217378: adds the owner's step (0x60) to the distance at 0x18; in phase 2, unless the
// owner has flag 0x80, moves to state 10 (also at 0xe0), sets flag 0x8000 on the owner, clears its 0x5c and, once,
// places it (func_000C6950 with the scale at 0x58).
void Object_000D8A40::func_000D91B0()
{
    Owner_000D91B0 *current = owner;
    distance = current->step + distance;
    if (phase == 2 && !(current->flags & 0x80)) {
        state = 10;
        next = 10;
        current->flags |= 0x8000;
        owner->value_5c = 0;
        if (!placed) {
            func_000C6950(owner->place, scale);
            placed = 1;
        }
    }
}
