struct Game {
    void *func_000128C0(int id);
};

struct Object_000A4D80 {
    void func_000A60D0();
};

// func_0010A750 calls func_00107AB0, this and func_00107B00 with the same object (`mov ecx, ebx`).
struct Object_00107FE0 {
    char unknown_0000[0x16b8];
    int targetId;

    void func_00107AE0();
};

extern Game *data_0022FCE0;

// Runs func_000A60D0 on the object whose id is at 0x16b8, when it exists.
void Object_00107FE0::func_00107AE0()
{
    Object_000A4D80 *target = (Object_000A4D80 *)data_0022FCE0->func_000128C0(targetId);
    if (target) {
        target->func_000A60D0();
    }
}
