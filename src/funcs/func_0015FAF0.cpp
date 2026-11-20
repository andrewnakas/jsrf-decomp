/* sym: ??0MGameInput8@@QAE@PAUUnknown@@@Z = 0x001616F0 */
struct Unknown;

// MGameInput8, the class its factory (table 0x1E185C, next to the "MUSASHI.MGameInput8.1" strings) creates; its table
// is at 0x1E1900.
struct MGameInput8 {
    MGameInput8(Unknown *outer);

    char unknown_00[0x4c];
};

// Creates a MGameInput8 (0x4c bytes, constructor 0x1616F0) aggregated by the outer object, if any. E_INVALIDARG for a
// null result pointer, E_OUTOFMEMORY when the allocation fails; if the constructor throws, its exception handler
// frees the memory.
long __stdcall func_0015FAF0(Unknown *outer, void **object)
{
    if (object) {
        MGameInput8 *created = new MGameInput8(outer);
        if (created) {
            *object = created;
            return 0;
        }
        *object = 0;
        return 0x8007000E;
    }
    return 0x80070057;
}
