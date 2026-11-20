struct Game {
    void *func_000128C0(int id);
};

struct Object_0010E0A0 {
    void func_0010E0A0(int amount);
};

struct Object_00107E60 {
    char unknown_00[0x54];
    int targetId;

    void func_00107E60(int amount);
};

extern Game *data_0022FCE0;

void Object_00107E60::func_00107E60(int amount)
{
    Object_0010E0A0 *target = (Object_0010E0A0 *)data_0022FCE0->func_000128C0(targetId);
    if (target) {
        target->func_0010E0A0(amount);
    }
}
