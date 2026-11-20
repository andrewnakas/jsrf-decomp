struct Game {
    void *func_000128C0(int id);
};

struct Object_000732A0 {
    void func_000732A0();
};

struct Object_00074260 {
    void func_000743C0();
};

// The objects with ids 0x115e to 0x1162 (table 0x1D2020).
struct Object_00107FE0 {
    char unknown_0000[0x8c];
    int id_8c;
    int id_90;
    char unknown_0094[0x166c];
    unsigned int flags;

    void func_00107B90();
};

extern Game *data_0022FCE0;

// Takes out the object whose id is at 0x8c (func_000732A0) and ends the one whose id is at 0x90 (func_000743C0,
// then flag 0x10000000 at 0x1700), clearing both ids.
void Object_00107FE0::func_00107B90()
{
    if (id_8c != -1) {
        Object_000732A0 *object = (Object_000732A0 *)data_0022FCE0->func_000128C0(id_8c);
        if (object) {
            object->func_000732A0();
        }
        id_8c = -1;
    }
    if (id_90 != -1) {
        Object_00074260 *object = (Object_00074260 *)data_0022FCE0->func_000128C0(id_90);
        if (object) {
            object->func_000743C0();
        }
        flags |= 0x10000000;
        id_90 = -1;
    }
}
