/* sym: ??0MGameSound8@@QAE@PAUUnknown@@@Z = 0x001693E0 */
struct Unknown;

// MGameSound8, the class its factory (table 0x1E38E4, after the "MUSASHI.MGameSound8.1" strings) creates; its tables
// are at 0x1E3A70 and 0x1E3A5C.
struct MGameSound8 {
    MGameSound8(Unknown *outer);

    char unknown_00[0x2c];
};

// Creates a MGameSound8 (0x2c bytes, constructor 0x1693E0) aggregated by the outer object, if any. E_INVALIDARG for a
// null result pointer, E_OUTOFMEMORY when the allocation fails; if the constructor throws, its exception handler
// frees the memory.
long __stdcall func_00167F00(Unknown *outer, void **object)
{
    if (object) {
        MGameSound8 *created = new MGameSound8(outer);
        if (created) {
            *object = created;
            return 0;
        }
        *object = 0;
        return 0x8007000E;
    }
    return 0x80070057;
}
