struct Game {
    void *func_000128C0(int id);
};

struct Object_000A1C50 {
    void func_000A0610(int value);
};

struct Object_000A63C0 {
    char unknown_000[0x8b4];
    int state_8b4;
    char unknown_8b8[0x1c];
    int target_id;

    void func_000A6190();
};

extern Game *data_0022FCE0;

// Clears the field at 0x8b4 and runs func_000A0610(0) on the object whose id is at 0x8d4, when it exists.
void Object_000A63C0::func_000A6190()
{
    state_8b4 = 0;
    Object_000A1C50 *target = (Object_000A1C50 *)data_0022FCE0->func_000128C0(target_id);
    if (target) {
        target->func_000A0610(0);
    }
}
