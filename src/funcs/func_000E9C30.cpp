struct Vector3 {
    float x;
    float y;
    float z;
};

extern "C" void *memset(void *destination, int value, unsigned int size);

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000651E0(int id, void *data, Vector3 *position);
};

struct Object_00046670 {
    float func_000466C0(Vector3 *position, int id);
};

extern Object_00046670 data_001F93C8;

// The object a behaviour serves (the owner type of the Object_000CC600 family).
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0xc];
    int value_5c;
    char unknown_60[0x44];
    unsigned int flags;
    Vector3 *next;
};

// The path at 0x118: its length at 0x48.
struct Path_000E9C30 {
    char unknown_00[0x48];
    int length;
};

// The object func_000E7F50 builds; this is a handler of the member pointers at 0x2584C8 that slot 0 of
// Object_000EA3B0 (func_000EA6A0) runs, filled in by the dynamic initializer func_0018C000.
struct Object_000E7F50 {
    int unknown_000;
    Object_000C5B50 *owner;
    int state;
    char unknown_00c[4];
    int count;
    Vector3 position;
    char unknown_020[0xc];
    float height;
    char unknown_030[0x70];
    Vector3 *route;
    char unknown_0a4[8];
    int value_0ac;
    char unknown_0b0[0x30];
    int sounds[4];
    int values_0f0[4];
    int sound_100;
    int values_104[3];
    char unknown_110[8];
    Path_000E9C30 *path;
    int length;
    int value_120;
    int value_124;
    char unknown_128[4];
    int value_12c;
    char unknown_130[8];
    int value_138;
    int value_13c;
    char unknown_140[4];
    int value_144;

    void func_000E9C30();
};

// A handler of the member pointers at 0x2584C8: state 1 with the counts cleared and the path's length at 0x11c; puts
// this and the owner at the first point of the route at 0xa0 (the owner heading for the next, its flags cleared),
// clears 0xf0 and 0x104; starts four 0x3b sounds at 0xe0 and a 0x3c one at 0x100 (cleared without the sound object);
// and takes the height under the owner from data_001F93C8 into 0x2c.
void Object_000E7F50::func_000E9C30()
{
    value_144 = 0;
    count = 0;
    state = 1;
    length = path->length;
    value_120 = 0;
    value_124 = 0;
    value_13c = 0;
    value_138 = 0;
    value_12c = 0;
    owner->value_5c = 0;
    position = *route;
    owner->position = *route;
    value_0ac = 1;
    owner->next = route + 1;
    owner->flags = 0;
    memset(values_0f0, 0, sizeof(values_0f0));
    memset(values_104, 0, sizeof(values_104));
    Object_000607B0 *player = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (player) {
        for (int i = 0; i < 4; i++) {
            sounds[i] = player->func_000651E0(0x3b, 0, 0);
        }
        sound_100 = player->func_000651E0(0x3c, 0, 0);
    } else {
        memset(sounds, 0, sizeof(sounds));
        sound_100 = 0;
    }
    height = data_001F93C8.func_000466C0(&owner->position, -1);
}
