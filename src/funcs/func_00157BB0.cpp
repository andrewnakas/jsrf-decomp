struct Interface {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

// A class whose table is at 0x1E144C (11 slots).
struct Object_001E144C {
    virtual long __stdcall func_00157D70(const void *iid, void **object);  // slot 0

    Interface *object;
    unsigned long value_08;
};

long __stdcall func_00159F30(void *unused, void *object);

// Releases the object at +4 until its Release returns 0, clears +8 and takes the object off the list at 0x265120.
void __stdcall func_00157BB0(Object_001E144C *object)
{
    if (object->object) {
        while (object->object->slot2())
            ;
        object->object = 0;
    }
    object->value_08 = 0;
    func_00159F30(&object->object, object);
}
