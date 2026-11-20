struct Game {
    void *func_000128C0(int id);
};

struct Object_000FEC10 {
    void func_000FF860(unsigned int mask, int set);
};

extern Game *data_0022FCE0;

// Passes the mask and the flag on to func_000FF860 of object 0x1163, when it exists.
void func_000FEB30(unsigned int mask, int set)
{
    Object_000FEC10 *object = (Object_000FEC10 *)data_0022FCE0->func_000128C0(0x1163);
    if (object) {
        object->func_000FF860(mask, set);
    }
}
