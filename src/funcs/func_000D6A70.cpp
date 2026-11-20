struct Desc_000D6350 {
    char unknown_00[0x5c];
    float speed;
};

// The behaviour func_000D6350 builds; this is entry 4 of its handler table at 0x21718C (the pointer at 0x74).
struct Object_000D6350 {
    void *vtable;
    Desc_000D6350 *desc;
    int state;
    char unknown_0c[4];
    int count;
    float x;
    char unknown_18[4];
    float z;
    float dir_x;
    char unknown_24[4];
    float dir_z;

    void func_000D6A70();
};

// Counts up at 0x10; at 120, state 2. Otherwise, while the speed of the object served is positive, moves x and z
// along (0x20, 0x28) by it and slows it by 1/12, never below 0.
void Object_000D6350::func_000D6A70()
{
    if (++count < 120) {
        if (desc->speed > 0.0f) {
            x += dir_x * desc->speed;
            z += dir_z * desc->speed;
            desc->speed -= 1.0f / 12.0f;
            if (desc->speed < 0.0f) {
                desc->speed = 0.0f;
            }
        }
    } else {
        state = 2;
    }
}
