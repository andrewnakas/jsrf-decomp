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
    void func_000606C0(int sound, Vector3 *position);
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
    char unknown_014[0x94];
    unsigned int rounds;
    char unknown_0ac[0x20];
    int sounds[5];
    char unknown_0e0[0x64];
    int value_144;

    void func_000EA8C0();
    void func_000EA080(Vector3 *out);
    void func_000EA100(Vector3 *out);
};

// A handler of the member pointers at 0x2584C8: moves the five sounds at 0xcc to the positions func_000EA100 gives;
// after 240 frames (0x10), state 5 with the count restarted and sound 0x40 heading down from the position
// func_000EA080 gives while fewer than five rounds (0xa8) have passed, else state 7 with 4 at 0x144.
void Object_000E7F50::func_000EA8C0()
{
    Vector3 positions[5];
    func_000EA100(positions);
    Object_000607B0 *player = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (player) {
        player->func_000606C0(sounds[0], &positions[0]);
    }
    player = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (player) {
        player->func_000606C0(sounds[1], &positions[1]);
    }
    player = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (player) {
        player->func_000606C0(sounds[2], &positions[2]);
    }
    player = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (player) {
        player->func_000606C0(sounds[3], &positions[3]);
    }
    player = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (player) {
        player->func_000606C0(sounds[4], &positions[4]);
    }
    if (++count > 240) {
        if (rounds < 5) {
            state = 5;
            Vector3 position;
            Vector3 direction;
            count = 0;
            direction.x = 0.0f;
            direction.y = -1.0f;
            direction.z = 0.0f;
            func_000EA080(&position);
            player = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
            if (player) {
                player->func_000651E0(0x40, &position, &direction);
            }
        } else {
            state = 7;
            value_144 = 4;
        }
    }
}
