struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    void func_00060810(int key);
};

// Passes a key to func_00060810 of object 0xe8, when it exists.
void func_00060BA0(int key)
{
    Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (object) {
        object->func_00060810(key);
    }
}
