/* sym: ??0Object_001E3D30@@QAE@PAUUnknown@@@Z = 0x00173440 */
struct Unknown;

// The class whose table is at 0x1E3D30: the one the MRIFFFile factory (0x1E3CD8) creates for IID_IUnknown and the
// interface 0x1E3D10.
struct Object_001E3D30 {
    Object_001E3D30(Unknown *outer);

    char unknown_00[0x118];
};

// Creates the object (0x118 bytes, constructor 0x173440) aggregated by the outer object, if any. E_INVALIDARG for a
// null result pointer, E_OUTOFMEMORY when the allocation fails; if the constructor throws, its exception handler
// frees the memory.
long __stdcall func_00172D30(Unknown *outer, void **object)
{
    if (object) {
        Object_001E3D30 *created = new Object_001E3D30(outer);
        if (created) {
            *object = created;
            return 0;
        }
        *object = 0;
        return 0x8007000E;
    }
    return 0x80070057;
}
