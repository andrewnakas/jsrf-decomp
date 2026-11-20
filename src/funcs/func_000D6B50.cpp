struct Vector3 {
    float x;
    float y;
    float z;
};
// The object a behaviour serves (the owner type of the Object_000CC600 family).
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0xc];
    float speed;
    char unknown_60[0x44];
    unsigned int flags;

    int func_000C5B10(int message, void *data);
    void func_000C5B50(int *handle);
};

// The behaviour func_000D6350 builds; this is an entry of its handler table at 0x21718C (the pointer at 0x74), and
// the same code serves Object_000E7F50's table at 0x219144.
struct Object_000D6350 {
    void *vtable;
    Object_000C5B50 *desc;
    int state;
    char unknown_0c[4];
    int count;
    char unknown_14[0x2b8];
    int handle_2cc;

    void func_000D6B50();
};

// Entry 7: counts up at 0x10; past 10, state 8, the object served gains the flags 0x1000000 and 0x20 at 0xa4 and
// gets message 0x21 with its position.
void Object_000D6350::func_000D6B50()
{
    if (++count > 10) {
        state = 8;
        desc->flags |= 0x1000000;
        desc->flags |= 0x20;
        desc->func_000C5B10(0x21, &desc->position);
    }
}
