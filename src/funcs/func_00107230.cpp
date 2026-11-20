struct Game {
    void *func_000128C0(int id);
};

struct Object_00107FE0 {
    int func_00107FE0();
};

extern Game *data_0022FCE0;

// For an id from 0x115e to 0x1162: returns func_00107FE0 of that object; 1 when the id is out of range or
// the object does not exist.
int func_00107230(unsigned int id)
{
    if (id >= 0x115e && id <= 0x1162) {
        Object_00107FE0 *target = (Object_00107FE0 *)data_0022FCE0->func_000128C0(id);
        if (target) {
            return target->func_00107FE0();
        }
    }
    return 1;
}
