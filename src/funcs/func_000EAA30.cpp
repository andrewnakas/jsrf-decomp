struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000651E0(int id, void *data, Vector3 *position);
};

// The object a behaviour serves (the owner type of the Object_000CC600 family).
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;

    int func_000C5B10(int message, void *data);
    void func_000C5B50(int *handle);
};

void func_000EB160(Object_000C5B50 *owner, Vector3 *position);

// The object func_000E7F50 builds; this is a handler of the member pointers at 0x2584C8 that slot 0 of
// Object_000EA3B0 (func_000EA6A0) runs, filled in by the dynamic initializer func_0018C000.
struct Object_000E7F50 {
    int unknown_000;
    Object_000C5B50 *owner;
    int state;
    char unknown_00c[4];
    int count;
    char unknown_014[0x54];
    int handle;
    char unknown_06c[0x3c];
    unsigned int rounds;
    char unknown_0ac[0x18];
    int timer;
    int shots;
    int sound;
    char unknown_0d0[0x74];
    int value_144;

    void func_000EAA30();
    void func_000EA080(Vector3 *out);
};

// A handler of the member pointers at 0x2584C8: counts up at 0x10; at 13, a func_000EB160 object at the owner's
// position lifted by 5, state 6 with 5 at 0x144, the counts reset (one shot at 0xc8), sound 0x41 there; for the first
// four rounds (0xa8) the position comes from func_000EA080 and sound 0x3f there is kept at 0xcc; then the owner's
// func_000C5B50 with the handle at 0x68 and message 0x36 at the position.
void Object_000E7F50::func_000EAA30()
{
    if (++count >= 13) {
        Vector3 position = owner->position;
        position.y += 5.0f;
        func_000EB160(owner, &position);
        state = 6;
        value_144 = 5;
        count = 0;
        timer = 0;
        shots = 1;
        Object_000607B0 *sounds = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (sounds) {
            sounds->func_000651E0(0x41, &position, 0);
        }
        if (++rounds < 5) {
            func_000EA080(&position);
            sounds = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
            if (sounds) {
                sound = sounds->func_000651E0(0x3f, &position, 0);
            }
        }
        owner->func_000C5B50(&handle);
        owner->func_000C5B10(0x36, &position);
    }
}
