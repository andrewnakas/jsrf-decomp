struct Game {
    void *func_000128C0(int id);
};

struct Object_000A4C00 {
    int func_000A4C00();
};

// func_0010A750 calls this, func_00107AE0 and func_00107B00 with the same object (`mov ecx, ebx`).
struct Object_00107B20 {
    char unknown_0000[0x16b8];
    int targetId;

    int func_00107AB0();
};

extern Game *data_0022FCE0;

int Object_00107B20::func_00107AB0()
{
    int result = 0;
    Object_000A4C00 *target = (Object_000A4C00 *)data_0022FCE0->func_000128C0(targetId);
    if (target) {
        result = target->func_000A4C00();
    }
    return result;
}
