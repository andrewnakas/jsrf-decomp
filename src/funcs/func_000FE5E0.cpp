struct Game {
    void *func_000128C0(int id);
};

// The children object 0x1165 keeps by id.
struct Object_000FDDC0 {
    void func_000FDDE0();
};

// Object 0x1165 (constructor func_000FE740, destructor func_000FDF30).
struct Object_000FDF30 {
    char unknown_000[0xa4];
    int ids[7];
};

extern Game *data_0022FCE0;

// Calls func_000FDDE0 on the child of object 0x1165 whose id is entry `index` of its list at 0xa4, when both
// exist.
void func_000FE5E0(int index)
{
    Object_000FDF30 *object = (Object_000FDF30 *)data_0022FCE0->func_000128C0(0x1165);
    if (object) {
        int id = object->ids[index];
        if (id != -1) {
            Object_000FDDC0 *child = (Object_000FDDC0 *)data_0022FCE0->func_000128C0(id);
            if (child) {
                child->func_000FDDE0();
            }
        }
    }
}
