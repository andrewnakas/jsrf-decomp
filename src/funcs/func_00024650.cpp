struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_00024480 {
    char unknown_00[0xc0];
    int unknown_c0;
};

// Returns the field at +0xc0 of object 6, or 1 when there is no object 6.
int func_00024650()
{
    Object_00024480 *object = (Object_00024480 *)data_0022FCE0->func_000128C0(6);
    if (object) {
        return object->unknown_c0;
    }
    return 1;
}
