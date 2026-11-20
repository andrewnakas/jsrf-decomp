struct Vector3 {
    float x;
    float y;
    float z;
};

// The object a behaviour serves (the owner type of the Object_000CC600 family).
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;

    int func_000C5B10(int message, void *data);
};

void func_000EB160(Object_000C5B50 *owner, Vector3 *position);

// The object func_000E7F50 builds; this is a handler of the member pointers at 0x2584C8 its slot 13
// (func_000EA6A0) runs, filled in by the dynamic initializer func_0018C000.
struct Object_000E7F50 {
    int unknown_000;
    Object_000C5B50 *owner;
    int state;
    char unknown_00c[4];
    int count;
    char unknown_014[0xb0];
    int timer;
    unsigned int shots;

    void func_000E9D80();
};

// Entry 6 of the handlers at 0x2584C8: counts up at 0x10 and 0xc4; every 12 at 0xc4, a func_000EB160 object and
// message 0x36 at the owner's position lifted by 5; after three of them (0xc8), state 4.
void Object_000E7F50::func_000E9D80()
{
    count++;
    if (++timer >= 12.0f) {
        timer = 0;
        Vector3 position = owner->position;
        position.y += 5.0f;
        func_000EB160(owner, &position);
        owner->func_000C5B10(0x36, &position);
        if (++shots >= 3) {
            state = 4;
        }
    }
}
