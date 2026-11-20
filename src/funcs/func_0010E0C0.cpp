struct Game {
    void *func_000128C0(int id);
};

// The objects with ids 0x115e to 0x1162 (table 0x1D2020).
struct Object_00107FE0 {
    void func_00108640(int index, int value);
};

struct Object_0010E0C0 {
    char unknown_000[0xb8];
    int value_b8;
    int value_bc;
    char unknown_0c0[0x40];
    int id_100;

    void func_0010E0C0(int value);
};

extern Game *data_0022FCE0;

// Keeps the value at 0xb8 and 0xbc and passes it as entry 5 to func_00108640 of the object whose id is at 0x100
// (one of the objects 0x115e to 0x1162; func_00107FE0's func_00109850 calls this).
void Object_0010E0C0::func_0010E0C0(int value)
{
    value_bc = value;
    value_b8 = value;
    Object_00107FE0 *object = (Object_00107FE0 *)data_0022FCE0->func_000128C0(id_100);
    object->func_00108640(5, value_b8);
}
