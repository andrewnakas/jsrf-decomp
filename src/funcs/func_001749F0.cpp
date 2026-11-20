/* sym: ??0MemStream@@QAE@PAUUnknown@@@Z = 0x00175BC0 */
struct Unknown;

// MemStream, the class its factory (table 0x1E3E80, after the "MUSASHI.MemStream.1" strings) creates; its tables are
// at 0x1E3EA8 and 0x1E3E98.
struct MemStream {
    MemStream(Unknown *outer);

    char unknown_00[0x78];
};

// Creates a MemStream (0x78 bytes, constructor 0x175BC0) aggregated by the outer object, if any. E_INVALIDARG for a
// null result pointer, E_OUTOFMEMORY when the allocation fails; if the constructor throws, its exception handler
// frees the memory.
long __stdcall func_001749F0(Unknown *outer, void **object)
{
    if (object) {
        MemStream *created = new MemStream(outer);
        if (created) {
            *object = created;
            return 0;
        }
        *object = 0;
        return 0x8007000E;
    }
    return 0x80070057;
}
