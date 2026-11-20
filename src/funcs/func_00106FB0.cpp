struct Game {
    void *func_000128C0(int id);
};

// The objects with ids 0x115e to 0x1162 (table 0x1D2020).
struct Object_00107FE0 {
    int func_00107B50();
};

extern Game *data_0022FCE0;

// func_00107B50 of the object with that id (one of 0x115e to 0x1162), or 0 for another id or a missing object.
int func_00106FB0(unsigned int id)
{
    int result = 0;
    if (id < 0x115e || id > 0x1162) {
        return 0;
    }
    Object_00107FE0 *object = (Object_00107FE0 *)data_0022FCE0->func_000128C0(id);
    if (object) {
        result = object->func_00107B50();
    }
    return result;
}
