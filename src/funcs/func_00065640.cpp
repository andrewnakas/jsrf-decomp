struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000655D0(int index, int first, int second, int third);
};

// Passes three values to func_000655D0 of object 0xe8 with index -1 and returns its result; 0 when the object
// does not exist.
int func_00065640(int first, int second, int third)
{
    Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (!object) {
        return 0;
    }
    return object->func_000655D0(-1, first, second, third);
}
