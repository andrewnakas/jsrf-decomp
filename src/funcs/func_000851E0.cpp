extern "C" void *memset(void *destination, int value, unsigned int size);

struct Vector3 {
    float x;
    float y;
    float z;
};

// Object 0x50 (constructor 0x85280, destructor 0x85410): a state machine whose handlers are in the table at
// 0x20D9C8.
struct Object_00086060 {
    char unknown_000[0x44];
    int state;
    Vector3 first;
    Vector3 second;
    char unknown_060[0x18];
    Vector3 velocity;
    char unknown_084[8];
    int unknown_08c;
    int unknown_090;
    char unknown_094[4];
    int unknown_098;
    unsigned int flags;
    char unknown_0a0[0x8c];
    int unknown_12c;
    char unknown_130[0xc];
    int unknown_13c;

    void func_000851E0(int id, const Vector3 *position);
};

extern void (Object_00086060::*data_0020D9C8[])();


// Starts over at a position: clears flag 1 and the state, puts the position at +0x48 and +0x54, sets flag 0x20,
// +0x98 to -1, clears +0x90, the velocity at +0x78 and +0x8c, runs the handler of state 0 and clears +0x12c and
// +0x13c. The id is not used.
void Object_00086060::func_000851E0(int, const Vector3 *position)
{
    flags &= ~1;
    state = 0;
    first = *position;
    second = *position;
    flags |= 0x20;
    unknown_098 = -1;
    unknown_090 = 0;
    memset(&velocity, 0, sizeof(velocity));
    unknown_08c = 0;
    (this->*data_0020D9C8[state])();
    unknown_12c = 0;
    unknown_13c = 0;
}
