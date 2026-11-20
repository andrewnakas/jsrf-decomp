struct Buffer {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual long __stdcall slot4(void **data, unsigned long flags);
};

// The base of the classes whose tables are at 0x1E1508, 0x1E1538 and 0x1E1568 (constructor 0x1589D0).
struct Object_001E14D8 {
    virtual long __stdcall func_00157F00_1(const void *iid, void **object);  // slot 0: E_UNEXPECTED, folded
    virtual unsigned long __stdcall func_00158A30();  // slot 1
    virtual unsigned long __stdcall func_0014D080_6();  // slot 2: returns 0, folded
    virtual long __stdcall func_001588F0();  // slot 3

    unsigned long words[0x40];
    Buffer *buffer;
    unsigned int stride;
    float value_10C;
    unsigned long value_110;
    unsigned long *target;
    unsigned long *source;
    void *data;
    long value_120;
    unsigned long value_124;
};

// Slot 3: clears +0x120, copies the four words at target to source and locks the buffer (its slot 4) into +0x11C.
long __stdcall Object_001E14D8::func_001588F0()
{
    value_120 = 0;
    source[0] = target[0];
    source[1] = target[1];
    source[2] = target[2];
    source[3] = target[3];
    return buffer->slot4(&data, 0);
}
