/* sym: ??0DirectInput8@@QAE@PAUUnknown@@@Z = 0x00166C30 */
struct Unknown;

// DirectInput8, the class its factory (table 0x1E20A0, after the "MUSASHI.DirectInput8.1" strings) creates; its table
// is at 0x1E21A0.
struct DirectInput8 {
    DirectInput8(Unknown *outer);

    char unknown_00[0x28];
};

// Creates a DirectInput8 (0x28 bytes, constructor 0x166C30) aggregated by the outer object, if any. E_INVALIDARG for
// a null result pointer, E_OUTOFMEMORY when the allocation fails; if the constructor throws, its exception handler
// frees the memory.
long __stdcall func_00166590(Unknown *outer, void **object)
{
    if (object) {
        DirectInput8 *created = new DirectInput8(outer);
        if (created) {
            *object = created;
            return 0;
        }
        *object = 0;
        return 0x8007000E;
    }
    return 0x80070057;
}
