struct Object_00118CB0 {
    int func_00117F40(int id, unsigned int index);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Splits a handle into its high and low halves and asks object 4's func_00117F40 about them; 0 without object 4.
int func_001186D0(int handle)
{
    Object_00118CB0 *object = (Object_00118CB0 *)data_0022FCE0->func_000128C0(4);
    if (!object) {
        return 0;
    }
    return object->func_00117F40((handle >> 16) & 0xffff, handle & 0xffff);
}
