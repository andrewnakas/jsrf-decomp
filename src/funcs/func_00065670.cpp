struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000655D0(int first, int second, int third, int fourth);
};

// Passes four values to func_000655D0 of object 0xe8 and returns what it says; 0 when the object does not exist.
int func_00065670(int first, int second, int third, int fourth)
{
    Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (!object) {
        return 0;
    }
    return object->func_000655D0(first, second, third, fourth);
}
