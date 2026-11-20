struct Interface {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

// The base of the classes whose tables are at 0x1E14D8, 0x1E1508, 0x1E1538 and 0x1E1568 (created by 0x158A80).
struct Object_001E14D8 {
    virtual long __stdcall func_00157F00_1(const void *iid, void **object);  // slot 0: E_UNEXPECTED, folded

    char unknown_04[0x100];
    Interface *object;
    unsigned long value;
};

// Releases the object at +0x104 until its Release returns 0 and clears +0x104 and +0x108.
void __stdcall func_00158750(Object_001E14D8 *object)
{
    if (object->object) {
        while (object->object->slot2())
            ;
        object->object = 0;
        object->value = 0;
    }
}
