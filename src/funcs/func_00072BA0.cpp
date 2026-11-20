struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The object 0x1163.
struct Object_000FEDB0 {
    void func_000FEF40(int id, int value);
    void func_000FEFE0(int id, int value);
};

// The node class whose table is at 0x1CCB68 (constructor 0x73500, made by 0x109300; destructor 0x73AD0).
struct Object_00073AD0 {
    char unknown_00[8];
    int id;
    char unknown_0c[0x38];
    unsigned int flags;
    char unknown_48[0x5c];
    int unknown_a4;

    void func_00072BA0();
};

// Called by 0x72C00 and slot 1 (0x73C20). Once only (bit 29 of +0x44): passes the node's id and its word at +0xa4 to
// func_000FEF40 and func_000FEFE0 of object 0x1163.
void Object_00073AD0::func_00072BA0()
{
    if (!(flags & 0x20000000)) {
        Object_000FEDB0 *object = (Object_000FEDB0 *)data_0022FCE0->func_000128C0(0x1163);
        if (object) {
            object->func_000FEF40(id, unknown_a4);
            object->func_000FEFE0(id, unknown_a4);
            flags |= 0x20000000;
        }
    }
}
