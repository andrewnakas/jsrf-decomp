struct Game {
    void *func_000128C0(int id);
};

struct Object_000A4C00 {
    void func_000A60D0();
};

struct Object_00107AB0 {
    char unknown_0000[0x16b8];
    int targetId;

    void func_00107AE0();
};

extern Game *data_0022FCE0;

// Runs func_000A60D0 on the object whose id is at 0x16b8, when it exists.
void Object_00107AB0::func_00107AE0()
{
    Object_000A4C00 *target = (Object_000A4C00 *)data_0022FCE0->func_000128C0(targetId);
    if (target) {
        target->func_000A60D0();
    }
}
