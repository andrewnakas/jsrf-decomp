extern "C" void *memset(void *destination, int value, unsigned int size);

struct Vector3 {
    float x;
    float y;
    float z;
};

float __fastcall func_0014C460(Vector3 *out, const Vector3 *in);

// Object 0x50 (constructor 0x85280, destructor 0x85410): a state machine whose handlers are in the table at
// 0x20D9C8.
struct Object_00086060 {
    char unknown_000[0x44];
    int state;
    Vector3 first;
    Vector3 second;
    char unknown_060[0xc];
    Vector3 direction;
    Vector3 velocity;
    char unknown_084[8];
    int unknown_08c;
    int unknown_090;
    char unknown_094[4];
    int unknown_098;
    unsigned int flags;

    void func_000850C0(int state, Vector3 *position, Vector3 *direction, Vector3 *start, int value);
};

extern void (Object_00086060::*data_0020D9C8[])();

// Starts state `state`: the start (or the position) at +0x48, the position at +0x54, flag 0x20, the value at +0x98,
// +0x90 cleared; a direction is kept flattened at +0x6c (a zero one is cleared and sets flag 2). Clears the velocity at
// +0x78 and +0x8c and runs the state's handler.
void Object_00086060::func_000850C0(int state, Vector3 *position, Vector3 *direction, Vector3 *start, int value)
{
    this->state = state;
    if (start) {
        first = *start;
    } else {
        first = *position;
    }
    second = *position;
    unknown_098 = value;
    unknown_090 = 0;
    flags |= 0x20;
    if (direction) {
        this->direction = *direction;
        this->direction.y = 0.0f;
        if (func_0014C460(&this->direction, &this->direction) <= 0.0f) {
            this->direction.z = 0.0f;
            this->direction.x = 0.0f;
            flags |= 2;
        }
    }
    memset(&velocity, 0, sizeof(velocity));
    unknown_08c = 0;
    (this->*data_0020D9C8[this->state])();
}
