struct Game {
    void *func_000128C0(int id);
};

struct Target_000A6390 {
    char unknown_0000[0xf14];
    int value_f14;
};

struct Object_000A63C0 {
    char unknown_000[0x8d4];
    int target_id;

    void func_000A6390(int value);
};

extern Game *data_0022FCE0;

// Sets the field at 0xf14 of the object whose id is at 0x8d4 to the value, when it exists.
void Object_000A63C0::func_000A6390(int value)
{
    Target_000A6390 *target = (Target_000A6390 *)data_0022FCE0->func_000128C0(target_id);
    if (target) {
        target->value_f14 = value;
    }
}
