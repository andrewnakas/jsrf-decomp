/* sym: ??0Object_001E420C@@QAE@PAUUnknown@@@Z = 0x0017BA20 */
struct Unknown;

// The class whose table is at 0x1E420C: the one the MThread factory (0x1E4190) creates for the interface 0x1E41A8.
struct Object_001E420C {
    Object_001E420C(Unknown *outer);

    char unknown_00[0x50];
};

// Creates the object (0x50 bytes, constructor 0x17BA20) aggregated by the outer object, if any. E_INVALIDARG for a
// null result pointer, E_OUTOFMEMORY when the allocation fails; if the constructor throws, its exception handler
// frees the memory.
long __stdcall func_0017A770(Unknown *outer, void **object)
{
    if (object) {
        Object_001E420C *created = new Object_001E420C(outer);
        if (created) {
            *object = created;
            return 0;
        }
        *object = 0;
        return 0x8007000E;
    }
    return 0x80070057;
}
