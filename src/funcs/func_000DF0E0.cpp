struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 unknown_7c;
};

extern Object_000C1270 *data_00257CE4;

// The owner at 0x4.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0xc];
    float speed;
    char unknown_60[0x8];
    int count;
    char unknown_6c[0x38];
    unsigned int flags;
    Vector3 *target;

    int func_000C5B10(int message, void *data);
};

struct Object_000DCBC0 {
    char unknown_000[0x4];
    Object_000C5B50 *owner;
    int state;
    char unknown_00c[0x1b4];
    int next;

    void func_000DE6C0();
    void func_000DF0E0();
};

// A handler of the table at 0x217A20: stops the owner, aims it at the point at 0x7c of data_00257CE4, clears its
// flags 0x2, 0x20000 and 0x2000000 and its count at 0x68, gives it 15 for its position (func_000C5B10), moves to
// state 15 with 21 at 0x1c0 and goes on with func_000DE6C0.
void Object_000DCBC0::func_000DF0E0()
{
    owner->speed = 0.0f;
    owner->target = &data_00257CE4->unknown_7c;
    owner->flags &= ~0x2020002;
    owner->count = 0;
    owner->func_000C5B10(15, &owner->position);
    state = 15;
    next = 21;
    func_000DE6C0();
}
