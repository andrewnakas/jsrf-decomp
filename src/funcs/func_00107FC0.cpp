struct Game {
    void *func_000128C0(int id);
};

struct Object_0010A040 {
    void func_00109FA0(int mode);
};

struct Object_00107FE0 {
    char unknown_00[0x50];
    int targetId;

    void func_00107FC0(int mode);
};

extern Game *data_0022FCE0;

// Passes the mode on to func_00109FA0 of the object whose id is at 0x50, when it exists.
void Object_00107FE0::func_00107FC0(int mode)
{
    Object_0010A040 *target = (Object_0010A040 *)data_0022FCE0->func_000128C0(targetId);
    if (target) {
        target->func_00109FA0(mode);
    }
}
