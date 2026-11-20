/* sym: ??0Object_001E3FE4@@QAE@PAUUnknown@@@Z = 0x00177C40 */
struct Unknown;

// The class whose table is at 0x1E3FE4: the one the MFile2 factory (0x1E3F1C) creates for the interface 0x1E3F54.
struct Object_001E3FE4 {
    Object_001E3FE4(Unknown *outer);

    char unknown_00[0x34];
};

// Creates the object (0x34 bytes, constructor 0x177C40) aggregated by the outer object, if any. E_INVALIDARG for a
// null result pointer, E_OUTOFMEMORY when the allocation fails; if the constructor throws, its exception handler
// frees the memory.
long __stdcall func_001763C0(Unknown *outer, void **object)
{
    if (object) {
        Object_001E3FE4 *created = new Object_001E3FE4(outer);
        if (created) {
            *object = created;
            return 0;
        }
        *object = 0;
        return 0x8007000E;
    }
    return 0x80070057;
}
