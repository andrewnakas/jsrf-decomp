/* sym: ??0Object_001E41D8@@QAE@PAUUnknown@@@Z = 0x0017B150 */
struct Unknown;

// The class whose table is at 0x1E41D8: the one the MThread factory (0x1E4190) creates for IID_IUnknown and the
// interface 0x1E41B8.
struct Object_001E41D8 {
    Object_001E41D8(Unknown *outer);

    char unknown_00[0x50];
};

// Creates the object (0x50 bytes, constructor 0x17B150) aggregated by the outer object, if any. E_INVALIDARG for a
// null result pointer, E_OUTOFMEMORY when the allocation fails; if the constructor throws, its exception handler
// frees the memory.
long __stdcall func_0017A6D0(Unknown *outer, void **object)
{
    if (object) {
        Object_001E41D8 *created = new Object_001E41D8(outer);
        if (created) {
            *object = created;
            return 0;
        }
        *object = 0;
        return 0x8007000E;
    }
    return 0x80070057;
}
