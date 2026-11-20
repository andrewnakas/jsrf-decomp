/* sym: ??0Object_001E17E0@@QAE@XZ = 0x0015F280 */
struct Guid;
extern const Guid data_001E1804;

// A class whose table is at 0x1E17E0 (9 slots, 0x50 bytes, constructor 0x15F280; its base's table is at 0x1E17BC).
struct Object_001E17E0 {
    virtual long __stdcall func_00157F00_3(const void *iid, void **object);  // slot 0, at 0x15F800
    virtual unsigned long __stdcall func_0015F1B0_1();  // slot 1: AddRef, folded
    virtual unsigned long __stdcall func_0014D080_8();  // slot 2, at 0x15F360: Release
    virtual long __stdcall func_0015F1E0(unsigned long first, unsigned long second, unsigned long third);  // slot 3, at 0x15F860

    Object_001E17E0() throw();

    char unknown_04[0x4C];
};

// Creates an Object_001E17E0, gets its interface data_001E1804 into *object and sets it up (slot 3) with the three
// arguments. E_OUTOFMEMORY when the allocation fails; on a failure *object is null.
long __stdcall func_0015F2D0(unsigned long first, unsigned long second, unsigned long third, void **object)
{
    Object_001E17E0 *created = new Object_001E17E0;
    if (created) {
        long result = created->func_00157F00_3(&data_001E1804, object);
        if (result >= 0) {
            result = created->func_0015F1E0(first, second, third);
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
