/* sym: ??0Object_001E410C@@QAE@PAUUnknown@@@Z = 0x00179990 */
struct Unknown;

// The class whose table is at 0x1E410C: the one the MEvent factory (0x1E40C4) creates for IID_IUnknown and the
// interface 0x1E40EC.
struct Object_001E410C {
    Object_001E410C(Unknown *outer);

    char unknown_00[0x10];
};

// Creates the object (0x10 bytes, constructor 0x179990) aggregated by the outer object, if any. E_INVALIDARG for a
// null result pointer, E_OUTOFMEMORY when the allocation fails; if the constructor throws, its exception handler
// frees the memory.
long __stdcall func_001794A0(Unknown *outer, void **object)
{
    if (object) {
        Object_001E410C *created = new Object_001E410C(outer);
        if (created) {
            *object = created;
            return 0;
        }
        *object = 0;
        return 0x8007000E;
    }
    return 0x80070057;
}
