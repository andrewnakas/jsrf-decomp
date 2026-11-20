/* sym: ??0Object_001E3FB0@@QAE@PAUUnknown@@@Z = 0x00177280 */
struct Unknown;

// The class whose table is at 0x1E3FB0: the one the MFile2 factory (0x1E3F1C) creates for the interface 0x1E3F34.
struct Object_001E3FB0 {
    Object_001E3FB0(Unknown *outer);

    char unknown_00[0x18];
};

// Creates the object (0x18 bytes, constructor 0x177280) aggregated by the outer object, if any. E_INVALIDARG for a
// null result pointer, E_OUTOFMEMORY when the allocation fails; if the constructor throws, its exception handler
// frees the memory.
long __stdcall func_00176320(Unknown *outer, void **object)
{
    if (object) {
        Object_001E3FB0 *created = new Object_001E3FB0(outer);
        if (created) {
            *object = created;
            return 0;
        }
        *object = 0;
        return 0x8007000E;
    }
    return 0x80070057;
}
