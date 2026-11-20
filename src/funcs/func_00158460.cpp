/* sym: ?func_0014D080_5@Object_001E14B8@@UAGKXZ = 0x00158460 */
/* sym: ??1Object_001E1478@@QAE@XZ = 0x00157F40 */
// The base of the classes whose tables are at 0x1E1478, 0x1E1498 and 0x1E14B8 (created by 0x158490).
struct Object_001E1478 {
    virtual long __stdcall func_00157F00(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_001532F0_2();  // slot 1: AddRef, folded
    virtual unsigned long __stdcall func_0014D080_5();  // slot 2: returns 0, folded

    ~Object_001E1478();

    unsigned long references;
};

// The class whose table is at 0x1E14B8 (created by 0x158490).
struct Object_001E14B8 : Object_001E1478 {
    virtual unsigned long __stdcall func_0014D080_5();  // slot 2, at 0x00158460
};

void __stdcall func_0015B370(Object_001E14B8 *object);

// Release: the last reference lets func_0015B370 free what the object holds, then deletes it.
unsigned long __stdcall Object_001E14B8::func_0014D080_5()
{
    if (--references == 0) {
        func_0015B370(this);
        delete static_cast<Object_001E1478 *>(this);
        return 0;
    }
    return references;
}
