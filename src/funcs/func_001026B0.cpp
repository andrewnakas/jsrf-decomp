struct Game {
    void *func_000128C0(int id);
};

struct Object_000FC4A0 {
    int func_000FC4A0(int mode);
};

extern Game *data_0022FCE0;

// The child of Node whose table is at 0x1D1DD0 (constructor func_001022C0, which func_00108080 calls before
// this).
struct Object_001022C0 {
    char unknown_000[0xa4];
    int state;
    char unknown_0a8[4];
    int target_id;

    void func_001026B0();
};

// State 3, then mode 6 (func_000FC4A0) for the object whose id is at 0xac, when it exists.
void Object_001022C0::func_001026B0()
{
    state = 3;
    Object_000FC4A0 *target = (Object_000FC4A0 *)data_0022FCE0->func_000128C0(target_id);
    if (target) {
        target->func_000FC4A0(6);
    }
}
