struct Interface {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

// The base of the classes whose tables are at 0x1E1598, 0x1E15C0 and 0x1E15E8 (created by 0x158F00).
struct Object_001E1598 {
    virtual long __stdcall func_00157F00_2(const void *iid, void **object);  // slot 0: E_UNEXPECTED, folded

    Interface *object;
    unsigned long value_08;
};

long __stdcall func_00159F30(void *unused, void *object);

// Releases the object at +4 until its Release returns 0 and clears +4 and +8, then takes the object off the list
// at 0x265120.
void __stdcall func_0015C190(Object_001E1598 *object)
{
    if (object->object) {
        while (object->object->slot2())
            ;
        object->object = 0;
        object->value_08 = 0;
    }
    func_00159F30(&object->object, object);
}
