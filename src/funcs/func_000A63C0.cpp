struct Game {
    void *func_000128C0(int id);
};

struct Target_000A63C0 {
    char unknown_0000[0x10d8];
    int value_10d8;
};

struct Object_000A63C0 {
    char unknown_000[0x8d4];
    int target_id;

    void func_000A63C0();
};

extern Game *data_0022FCE0;

// Sets the field at 0x10d8 of the object whose id is at 0x8d4, when it exists.
void Object_000A63C0::func_000A63C0()
{
    Target_000A63C0 *target = (Target_000A63C0 *)data_0022FCE0->func_000128C0(target_id);
    if (target) {
        target->value_10d8 = 1;
    }
}
