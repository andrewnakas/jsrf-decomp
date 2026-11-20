/* sym: ?func_0014D080@Object_001E11B8@@UAGKXZ = 0x0014D7A0 */
/* sym: ??1Object_001E10E8@@QAE@XZ = 0x0014D4B0 */
// The Direct3D device wrapper (table 0x1E0F00); data_002650D8 points at the one in use.
struct Object_001E0F00 {
    long func_00154F80(void *resource);
};

extern Object_001E0F00 *data_002650D8;

// The base of the classes whose tables are at 0x1E10E8, 0x1E1150 (created by 0x14D800) and 0x1E11B8 (created by 0x14D8E0).
struct Object_001E10E8 {
    virtual long __stdcall func_0014D490(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0014D4A0();  // slot 1
    virtual unsigned long __stdcall func_0014D080();  // slot 2

    ~Object_001E10E8();

    void *first;
    void *second;
    char unknown_0C[0x14];
    unsigned long references;
};

// The class whose table is at 0x1E11B8 (created by 0x14D8E0).
struct Object_001E11B8 : Object_001E10E8 {
    virtual unsigned long __stdcall func_0014D080();  // slot 2, at 0x14D7A0
};

// Release: the last reference frees the blocks at +4 and +8, takes the object off the device's list and deletes it.
unsigned long __stdcall Object_001E11B8::func_0014D080()
{
    if (--references == 0) {
        if (first) {
            operator delete(first);
            first = 0;
        }
        if (second) {
            operator delete(second);
            second = 0;
        }
        data_002650D8->func_00154F80(this);
        delete static_cast<Object_001E10E8 *>(this);
        return 0;
    }
    return references;
}
