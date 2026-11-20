struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The objects with ids 0x115e to 0x1162.
struct Object_00107FE0 {
    int func_00107B20();
};

// For an id from 0x115e to 0x1162: what func_00107B20 of its object reports, 0 without one.
int func_00106F70(unsigned int id)
{
    int result = 0;
    if (id >= 0x115e && id <= 0x1162) {
        Object_00107FE0 *target = (Object_00107FE0 *)data_0022FCE0->func_000128C0(id);
        if (target) {
            result = target->func_00107B20();
        }
        return result;
    }
    return 0;
}
