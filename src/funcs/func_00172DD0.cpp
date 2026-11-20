/* sym: ??0Object_001E3D88@@QAE@PAUUnknown@@@Z = 0x00173B30 */
struct Unknown;

// The class whose table is at 0x1E3D88: the one the MRIFFFile factory (0x1E3CD8) creates for the interface 0x1E3CF0.
struct Object_001E3D88 {
    Object_001E3D88(Unknown *outer);

    char unknown_00[0x28];
};

// Creates the object (0x28 bytes, constructor 0x173B30) aggregated by the outer object, if any. E_INVALIDARG for a
// null result pointer, E_OUTOFMEMORY when the allocation fails; if the constructor throws, its exception handler
// frees the memory.
long __stdcall func_00172DD0(Unknown *outer, void **object)
{
    if (object) {
        Object_001E3D88 *created = new Object_001E3D88(outer);
        if (created) {
            *object = created;
            return 0;
        }
        *object = 0;
        return 0x8007000E;
    }
    return 0x80070057;
}
