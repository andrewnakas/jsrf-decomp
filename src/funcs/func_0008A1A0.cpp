struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    void func_000651E0(int kind, void *data, int flags);
};

struct Object_0008A1A0 {
    void func_0008A1A0(void *data);
};

// Passes data to func_000651E0 of object 0xe8 as kind 0xc, when the object exists.
void Object_0008A1A0::func_0008A1A0(void *data)
{
    Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (object) {
        object->func_000651E0(0xc, data, 0);
    }
}
