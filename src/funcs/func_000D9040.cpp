struct Vector3 {
    float x;
    float y;
    float z;
};

// Three angles (x, y, z).
struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

struct Object_00046670 {
    float func_000466C0(Vector3 *position, int index);
};

extern Object_00046670 data_001F93C8;

struct Owner_000D9040 {
    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;
    float speed;
    float climb;
    char unknown_64[0x4];
    int count;
    char unknown_6c[0x14];
    Vector3 start;
    Angles_000C1300 start_angles;
    char unknown_98[0xc];
    unsigned int flags;
};

struct Object_000D8A40 {
    char unknown_000[0x4];
    Owner_000D9040 *owner;
    int state;
    char unknown_00c[0x4];
    int ticks;
    Vector3 position;
    char unknown_020[0xc];
    float height;
    char unknown_030[0x18];
    int step_48;
    char unknown_04c[0x38];
    int placed;
    char unknown_088[0x4];
    unsigned int blinks;
    float shown;
    float fade;
    char unknown_098[0x4];
    int handle_9c;
    int pending;
    char unknown_0a4[0x3c];
    int next;
    int value_e4;
    char unknown_0e8[0xe0];
    int value_1c8;

    void func_000D8440();
    void func_000D9040();
};

// Resets the object and its owner: both back at the owner's start (0x80, angles 0x8c), the owner stopped with its
// count and flags cleared; state 1 with the counters, blinks and step cleared and the fade at 1; picks a step
// (func_000D8440); keeps at 0x9c what node 0xe8 gives for kind 0x47 (func_000651E0) and the ground height under the
// owner (func_000466C0 of data_001F93C8) at 0x2c.
void Object_000D8A40::func_000D9040()
{
    Owner_000D9040 *current = owner;
    Vector3 *start = &current->start;
    position = *start;
    current->position = *start;
    owner->climb = 0.0f;
    owner->speed = 0.0f;
    owner->angles = owner->start_angles;
    owner->count = 0;
    owner->flags = 0;
    placed = 0;
    ticks = 0;
    state = 1;
    value_e4 = 0;
    next = 0;
    value_1c8 = 0;
    blinks = 0;
    shown = 1.0f;
    fade = 1.0f;
    step_48 = 0;
    func_000D8440();
    Object_000607B0 *node = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (node) {
        handle_9c = node->func_000651E0(0x47, 0, 0);
    }
    pending = 0;
    height = data_001F93C8.func_000466C0(&owner->position, -1);
}
