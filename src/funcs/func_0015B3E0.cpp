// The base of the classes whose tables are at 0x1E14D8, 0x1E1508, 0x1E1538 and 0x1E1568 (created by 0x158A80).
struct Object_001E14D8 {
    virtual long __stdcall func_00157F00_1(const void *iid, void **object);  // slot 0: E_UNEXPECTED, folded

    unsigned long value_04;
};

void __stdcall func_00158750(Object_001E14D8 *object);
long __stdcall func_00159F30(void *unused, void *object);

// Releases what the object holds (func_00158750) and takes it off the list at 0x265120.
void __stdcall func_0015B3E0(Object_001E14D8 *object)
{
    func_00158750(object);
    func_00159F30(&object->value_04, object);
}
