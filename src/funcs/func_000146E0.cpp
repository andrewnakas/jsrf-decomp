struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_00014280 {
    void func_000140D0();
};

// Runs func_000140D0 on the object registered under an id, when it exists.
void func_000146E0(int id)
{
    Object_00014280 *object = (Object_00014280 *)data_0022FCE0->func_000128C0(id);
    if (object) {
        object->func_000140D0();
    }
}
