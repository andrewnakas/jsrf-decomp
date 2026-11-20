/* sym: ?func_0014D080_7@Object_001E15C0@@UAGKXZ = 0x00159050 */
/* sym: ??1Object_001E1598@@QAE@XZ = 0x00158EF0 */
struct Buffer;

// The base of the classes whose tables are at 0x1E1598, 0x1E15C0 and 0x1E15E8 (created by 0x158F00).
struct Object_001E1598 {
    virtual long __stdcall func_00157F00_2(const void *iid, void **object);  // slot 0: E_UNEXPECTED, folded
    virtual unsigned long __stdcall func_00158EE0();  // slot 1
    virtual unsigned long __stdcall func_0014D080_7();  // slot 2: returns 0, folded

    ~Object_001E1598();

    Buffer *buffer;
    unsigned long value_08;
    float value;
    unsigned long position;
    unsigned long value_14;
    unsigned long references;
};

// Kind 0 of 0x158F00; its Release is folded with kind 1's (0x1E15E8).
struct Object_001E15C0 : Object_001E1598 {
    virtual unsigned long __stdcall func_0014D080_7();  // slot 2, at 0x159050
};

void __stdcall func_0015C190(Object_001E1598 *object);

// Release: the last reference lets func_0015C190 take the object apart, then deletes it.
unsigned long __stdcall Object_001E15C0::func_0014D080_7()
{
    if (--references == 0) {
        func_0015C190(this);
        delete static_cast<Object_001E1598 *>(this);
        return 0;
    }
    return references;
}
