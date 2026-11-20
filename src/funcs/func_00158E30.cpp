struct Buffer {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual long __stdcall slot4(void **data, unsigned long flags);
    virtual long __stdcall slot5();
};

void func_00158DF0(void *destination, const void *source, unsigned int count, unsigned int stride);

// The base of the classes whose tables are at 0x1E1598, 0x1E15C0 and 0x1E15E8 (created by 0x158F00).
struct Object_001E1598 {
    virtual long __stdcall func_00158E30(const void *source, unsigned int count, unsigned int stride);  // slot 6

    Buffer *buffer;
};

// Locks the buffer (its slot 4), copies count 16-byte entries spaced stride apart into it (func_00158DF0) and
// unlocks it (slot 5).
long __stdcall Object_001E1598::func_00158E30(const void *source, unsigned int count, unsigned int stride)
{
    void *data = 0;
    long result = buffer->slot4(&data, 0);

    if (result < 0)
        return result;
    func_00158DF0(data, source, count, stride);
    buffer->slot5();
    return 0;
}
