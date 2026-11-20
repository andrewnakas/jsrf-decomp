int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);
long __stdcall func_00159F30(void *unused, void *object);

struct Interface {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

struct Holder {
    Interface *object;
    void *memory;
};

// One of the 0x20-byte slots of 0x1E1640's array.
struct Slot {
    Holder holder;
    char unknown_08[0x18];
};

// A class whose table is at 0x1E1640 (26 slots; Release 0x159D40, created by 0x159D70).
struct Object_001E1640 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall func_001583F0(Holder *holder);  // slot 5

    Slot *slots;
    unsigned int count;
};

// Takes the object apart (its Release, 0x159D40, calls it): empties every slot (slot 5), frees the array
// (func_00145A5D with 0x8000) and takes the object off the list at data_00265120 (func_00159F30).
void __stdcall func_00159C20(Object_001E1640 *object)
{
    if (object->slots) {
        for (unsigned int i = 0; i < object->count; i++)
            object->func_001583F0(&object->slots[i].holder);
        func_00145A5D(object->slots, 0, 0x8000);
        object->slots = 0;
        object->count = 0;
    }
    func_00159F30(&object->slots, object);
}
