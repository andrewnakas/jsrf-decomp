struct Game {
    void *func_000128C0(int id);
};

// The objects with ids 0x115e to 0x1162 (table 0x1D2020).
struct Object_00107FE0 {
    void func_00108280(int kind, int first, int second, int third);
};

extern Game *data_0022FCE0;

// func_00108280 of the object with that id, when the id is one of 0x115e to 0x1162 and the object exists.
void func_00106D40(unsigned int id, int kind, int first, int second, int third)
{
    Object_00107FE0 *object = (Object_00107FE0 *)data_0022FCE0->func_000128C0(id);
    if (id >= 0x115e && id <= 0x1162 && object) {
        object->func_00108280(kind, first, second, third);
    }
}
