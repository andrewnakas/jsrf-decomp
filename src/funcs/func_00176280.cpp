/* sym: ??0Object_001E3F84@@QAE@PAUUnknown@@@Z = 0x00176CA0 */
struct Unknown;

// The class whose table is at 0x1E3F84: the one the MFile2 factory (0x1E3F1C) creates for IID_IUnknown and the
// interface 0x1E3F64.
struct Object_001E3F84 {
    Object_001E3F84(Unknown *outer);

    char unknown_00[0x140];
};

// Creates the object (0x140 bytes, constructor 0x176CA0) aggregated by the outer object, if any. E_INVALIDARG for a
// null result pointer, E_OUTOFMEMORY when the allocation fails; if the constructor throws, its exception handler
// frees the memory.
long __stdcall func_00176280(Unknown *outer, void **object)
{
    if (object) {
        Object_001E3F84 *created = new Object_001E3F84(outer);
        if (created) {
            *object = created;
            return 0;
        }
        *object = 0;
        return 0x8007000E;
    }
    return 0x80070057;
}
