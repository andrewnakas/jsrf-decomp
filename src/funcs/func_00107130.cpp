struct Game {
    void *func_000128C0(int id);
};

struct Object_00107E40 {
    void func_00107E40();
};

extern Game *data_0022FCE0;

// For an id from 0x115e to 0x1162: runs func_00107E40 on that object, when it exists.
void func_00107130(unsigned int id)
{
    if (id >= 0x115e && id <= 0x1162) {
        Object_00107E40 *target = (Object_00107E40 *)data_0022FCE0->func_000128C0(id);
        if (target) {
            target->func_00107E40();
        }
    }
}
