struct Game {
    void *func_000128C0(int id);
};

struct Object_00107FE0 {
    void func_00107FC0(int mode);
};

extern Game *data_0022FCE0;

// For an id from 0x115e to 0x1162: runs func_00107FC0(mode) on that object, when it exists.
void func_00107200(unsigned int id, int mode)
{
    if (id >= 0x115e && id <= 0x1162) {
        Object_00107FE0 *target = (Object_00107FE0 *)data_0022FCE0->func_000128C0(id);
        if (target) {
            target->func_00107FC0(mode);
        }
    }
}
