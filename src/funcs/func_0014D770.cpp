/* sym: ?func_0014D080@Object_001E1150@@UAGKXZ = 0x0014D770 */
/* sym: ??1Object_001E10E8@@QAE@XZ = 0x0014D4B0 */
// The base of the classes whose tables are at 0x1E10E8, 0x1E1150 (created by 0x14D800) and 0x1E11B8 (created by 0x14D8E0).
struct Object_001E10E8 {
    virtual long __stdcall func_0014D490(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0014D4A0();  // slot 1
    virtual unsigned long __stdcall func_0014D080();  // slot 2

    ~Object_001E10E8();

    char unknown_04[0x1C];
    unsigned long references;
};

// The class whose table is at 0x1E1150 (created by 0x14D800).
struct Object_001E1150 : Object_001E10E8 {
    virtual unsigned long __stdcall func_0014D080();  // slot 2, at 0x14D770

    void func_0014D5F0();
};

// Release: the last reference lets func_0014D5F0 free what the object holds, then deletes it.
unsigned long __stdcall Object_001E1150::func_0014D080()
{
    if (--references == 0) {
        func_0014D5F0();
        delete static_cast<Object_001E10E8 *>(this);
        return 0;
    }
    return references;
}
