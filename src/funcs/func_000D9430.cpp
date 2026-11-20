struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
int func_0014C7D0(float first, float second);
float func_0014C820(float value);

// The owner at 0x4.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0xc];
    float speed;
    char unknown_60[0x48];
    Vector3 *target;

    int func_000C5B10(int message, void *data);
};

struct Object_000D8A40 {
    char unknown_000[0x4];
    Object_000C5B50 *owner;
    int state;
    char unknown_00c[0x38];
    int step;
    int step_48;
    char unknown_04c[0x4];
    unsigned int count;
    int pitch;
    char unknown_058[0x88];
    int next;

    int func_000D85E0();
    void func_000D8440();
    void func_000D9220();
    void func_000D9430();
};

// A handler of the table at 0x217378: when func_000D85E0 passes and the step it leads to (func_000D8440) is the one
// at 0x48 already, moves to state 2 (also at 0xe0), clears the count and the owner's speed (0x5c), keeps at 0x54 the pitch
// from 8.6 above the owner to its target (func_0014C7D0 of the height and the ground distance) and gives the owner
// 10 for its position (func_000C5B10). Goes on with func_000D9220 in every case.
void Object_000D8A40::func_000D9430()
{
    if (func_000D85E0()) {
        int previous = step_48;
        func_000D8440();
        if (previous == step) {
            state = 2;
            count = 0;
            next = 2;
            owner->speed = 0.0f;
            Vector3 from = owner->position;
            from.y += 8.6f;
            Vector3 offset;
            func_0014C4C0(&offset, owner->target, &from);
            pitch = func_0014C7D0(offset.y, func_0014C820(offset.x * offset.x + offset.z * offset.z));
            owner->func_000C5B10(10, &owner->position);
        }
    }
    func_000D9220();
}
