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
    char unknown_0ac[0x20];
    int sounds[5];
    char unknown_0e0[0x64];
    int value_144;

    void func_000EA7A0();
    void func_000EA100(Vector3 *out);
};

// A handler of the member pointers at 0x2584C8: with 3 at 0x144, state 4 with the rounds (0xa8) and the count
// cleared, five positions from func_000EA100 with sound 0x3f at the first and 0x3e at the others (kept at 0xcc..0xdc),
// and the owner's handle for message 0x35 at the first kept at 0x68.
void Object_000E7F50::func_000EA7A0()
{
    if (value_144 == 3) {
        Vector3 positions[5];
        state = 4;
        rounds = 0;
        count = 0;
        func_000EA100(positions);
        Object_000607B0 *player = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (player) {
            sounds[0] = player->func_000651E0(0x3f, &positions[0], 0);
        }
        player = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (player) {
            sounds[1] = player->func_000651E0(0x3e, &positions[1], 0);
        }
        player = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (player) {
            sounds[2] = player->func_000651E0(0x3e, &positions[2], 0);
        }
        player = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (player) {
            sounds[3] = player->func_000651E0(0x3e, &positions[3], 0);
        }
        player = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (player) {
            sounds[4] = player->func_000651E0(0x3e, &positions[4], 0);
        }
        handle = owner->func_000C5B10(0x35, &positions[0]);
    }
}
