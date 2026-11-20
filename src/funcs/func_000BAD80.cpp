struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The object func_000BAD80 finds by id: up to ten child ids at 0x8c, counted at 0xbc.
struct Object_000B40F0 {
    char unknown_00[0xd0];
    int value_d0;

    void func_000B40F0();
};

// Object 0xeb (constructor func_000BB1A0).
struct Object_000BAC20 {
    void func_000BAD80(int id);
};

// Runs func_000B40F0 on the object with this id, when it exists and the value at 0xd0 is not negative. It does not use
// `this`; func_0004C2A0 calls it on object 0xeb.
void Object_000BAC20::func_000BAD80(int id)
{
    Object_000B40F0 *object = (Object_000B40F0 *)data_0022FCE0->func_000128C0(id);
    if (object && !(object->value_d0 & 0x80000000)) {
        object->func_000B40F0();
    }
}
