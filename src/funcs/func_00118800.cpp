struct Bank_00118800 {
    int id;
    unsigned int count;
};

struct Object_00118CB0 {
    char unknown_0000[0x3f18];
    unsigned int count;
    Bank_00118800 *banks[256];

    int func_00117F40(int id, unsigned int index);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Calls func_00117F40 of object 4 for every entry of every loaded bank.
void func_00118800()
{
    Object_00118CB0 *object = (Object_00118CB0 *)data_0022FCE0->func_000128C0(4);
    if (object) {
        for (unsigned int i = 0; i < object->count; i++) {
            for (unsigned int j = 0; j < object->banks[i]->count; j++) {
                object->func_00117F40(object->banks[i]->id, j);
            }
        }
    }
}
