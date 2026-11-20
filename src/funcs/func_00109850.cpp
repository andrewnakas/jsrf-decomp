struct Game {
    void *func_000128C0(int id);
};

// What the object whose id is at 0x16b8 holds at 0x24 (func_00108640 sets its fields 0xcd4-0xfd0 by index).
struct Target_00109850 {
    char unknown_000[0xfa0];
    int value_fa0;
};

struct Holder_00109850 {
    char unknown_00[0x24];
    Target_00109850 *target;
};

struct Object_0010E0C0 {
    void func_0010E0C0(int value);
};

// The objects with ids 0x115e to 0x1162 (table 0x1D2020).
struct Object_00107FE0 {
    char unknown_0000[0x54];
    int id_54;
    char unknown_0058[0x1660];
    int id_16b8;

    void func_00109850(int value);
};

extern Game *data_0022FCE0;

// Passes the value to func_0010E0C0 of the object whose id is at 0x54 when it exists; otherwise stores it at 0xfa0
// of what the object whose id is at 0x16b8 holds at 0x24 (as func_00108640(5, value) does).
void Object_00107FE0::func_00109850(int value)
{
    Object_0010E0C0 *object = (Object_0010E0C0 *)data_0022FCE0->func_000128C0(id_54);
    if (object) {
        object->func_0010E0C0(value);
        return;
    }
    Holder_00109850 *holder = (Holder_00109850 *)data_0022FCE0->func_000128C0(id_16b8);
    if (holder && holder->target) {
        holder->target->value_fa0 = value;
    }
}
