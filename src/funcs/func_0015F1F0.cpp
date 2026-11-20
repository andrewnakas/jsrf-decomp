/* sym: ??0Object_001E1798@@QAE@XZ = 0x0015F190 */
struct Guid;
extern const Guid data_001E1814;

// A class whose table is at 0x1E1798 (9 slots, 0x50 bytes, constructor 0x15F190).
struct Object_001E1798 {
    virtual long __stdcall func_0015F580(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0015F1B0();  // slot 1
    virtual unsigned long __stdcall func_0015F2A0();  // slot 2: Release
    virtual long __stdcall func_0015F390(void *data, unsigned long size, unsigned long count);  // slot 3

    Object_001E1798() throw();

    char unknown_04[0x4C];
};

// Creates an Object_001E1798, gets its interface data_001E1814 into *object and fills it (slot 3) with the data.
// E_OUTOFMEMORY when the allocation fails; on a failure *object is null.
long __stdcall func_0015F1F0(void *data, unsigned long size, unsigned long count, void **object)
{
    Object_001E1798 *created = new Object_001E1798;
    if (created) {
        long result = created->func_0015F580(&data_001E1814, object);
        if (result >= 0) {
            result = created->func_0015F390(data, size, count);
            if (result >= 0)
                return 0;
        }
        delete created;
        *object = 0;
        return result;
    }
    *object = 0;
    return 0x8007000e;
}
