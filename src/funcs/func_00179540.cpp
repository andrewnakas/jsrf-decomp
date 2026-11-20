/* sym: ??0Object_001E4130@@QAE@PAUUnknown@@@Z = 0x0017A2A0 */
struct Unknown;

// The class whose table is at 0x1E4130: the one the MEvent factory (0x1E40C4) creates for the interface 0x1E40DC.
struct Object_001E4130 {
    Object_001E4130(Unknown *outer);

    char unknown_00[0x3c];
};

// Creates the object (0x3c bytes, constructor 0x17A2A0) aggregated by the outer object, if any. E_INVALIDARG for a
// null result pointer, E_OUTOFMEMORY when the allocation fails; if the constructor throws, its exception handler
// frees the memory.
long __stdcall func_00179540(Unknown *outer, void **object)
{
    if (object) {
        Object_001E4130 *created = new Object_001E4130(outer);
        if (created) {
            *object = created;
            return 0;
        }
        *object = 0;
        return 0x8007000E;
    }
    return 0x80070057;
}
