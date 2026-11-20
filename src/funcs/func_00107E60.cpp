struct Game {
    void *func_000128C0(int id);
};

struct Object_0010E0A0 {
    void func_0010E0A0(int amount);
};

// The objects with ids 0x115e to 0x1162: func_00107130, func_00107160, func_00107190 and func_00106F10 look
// them up by id and call func_00107E40, this, func_00109850 and func_00109300 on them.
struct Object_00107FE0 {
    char unknown_00[0x54];
    int targetId;

    void func_00107E60(int amount);
};

extern Game *data_0022FCE0;

void Object_00107FE0::func_00107E60(int amount)
{
    Object_0010E0A0 *target = (Object_0010E0A0 *)data_0022FCE0->func_000128C0(targetId);
    if (target) {
        target->func_0010E0A0(amount);
    }
}
