struct Game {
    void *func_000128C0(int id);
};

// The children object 0x1165 keeps by id (Object_000FDDC0's family); only slot 16 matters here.
struct Object_000FDDC0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
};

// Object 0x1165 (constructor func_000FE740, destructor func_000FDF30).
struct Object_000FDF30 {
    char unknown_000[0xa4];
    int ids[7];
};

extern Game *data_0022FCE0;

// Calls slot 16 of the child of object 0x1165 whose id is entry `index` of its list at 0xa4, when both exist (as
// func_000FE160 does on the object itself).
void func_000FE550(int index)
{
    Object_000FDF30 *object = (Object_000FDF30 *)data_0022FCE0->func_000128C0(0x1165);
    if (object) {
        int id = object->ids[index];
        if (id != -1) {
            Object_000FDDC0 *child = (Object_000FDDC0 *)data_0022FCE0->func_000128C0(id);
            if (child) {
                child->slot16();
            }
        }
    }
}
