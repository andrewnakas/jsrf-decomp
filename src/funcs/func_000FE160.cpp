struct Game {
    void *func_000128C0(int id);
};

struct Target_000FE160 {
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

// Object 0x1165 (func_000FE4E0 looks it up and calls func_000FDFB0 on it): func_000FDFB0 creates a child
// with `this` as its owner and keeps the child's id at 0xbc, entry 6 of the ids at 0xa4; the child's
// func_000FB9F0 calls this on its parent with 6.
struct Object_000FE190 {
    char unknown_00[0xa4];
    int ids[1]; // a list of object ids; its length is not known here

    void func_000FE160(int index);
};

extern Game *data_0022FCE0;

// Calls virtual slot 16 of the object whose id is entry `index` of the list at 0xa4, when the entry is set
// and the object exists.
void Object_000FE190::func_000FE160(int index)
{
    int id = ids[index];
    if (id != -1) {
        Target_000FE160 *target = (Target_000FE160 *)data_0022FCE0->func_000128C0(id);
        if (target) {
            target->slot16();
        }
    }
}
