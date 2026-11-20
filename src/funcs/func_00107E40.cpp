struct Game {
    void *func_000128C0(int id);
};

struct Object_0010E070 {
    void func_0010E070();
};

struct Object_00107E40 {
    char unknown_00[0x54];
    int targetId;

    void func_00107E40();
};

extern Game *data_0022FCE0;

void Object_00107E40::func_00107E40()
{
    Object_0010E070 *target = (Object_0010E070 *)data_0022FCE0->func_000128C0(targetId);
    if (target) {
        target->func_0010E070();
    }
}
