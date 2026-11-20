struct Game {
    void *func_000128C0(int id);
};

struct Object_0010A040 {
    int func_0010A040();
};

struct Object_00107FE0 {
    char unknown_00[0x50];
    int targetId;

    int func_00107FE0();
};

extern Game *data_0022FCE0;

int Object_00107FE0::func_00107FE0()
{
    Object_0010A040 *target = (Object_0010A040 *)data_0022FCE0->func_000128C0(targetId);
    if (target) {
        return target->func_0010A040();
    }
    return 1;
}
