/* sym: ?func_00158A60@Object_001E1568@@UAGJKKK@Z = 0x0015C040 */
struct Buffer {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual long __stdcall slot4(void **data, unsigned long flags);
    virtual long __stdcall slot5();
};

// The two ways kind 2 fills the buffer from count entries spaced stride apart (SSE code).
void func_0015BE30(void *destination, unsigned long source, unsigned long count, unsigned long stride,
                   const unsigned long *target, float scale);
void func_0015BF30(void *destination, unsigned long source, unsigned long count, unsigned long stride,
                   const unsigned long *target, float scale);

// The base of the classes whose tables are at 0x1E1508, 0x1E1538 and 0x1E1568 (constructor 0x1589D0).
struct Object_001E14D8 {
    virtual long __stdcall func_00158A60(unsigned long first, unsigned long second, unsigned long third);  // slot 6

    unsigned long words[0x40];
    Buffer *buffer;
    unsigned int stride;
    float value_10C;
    unsigned long value_110;
    unsigned long *target;
};

// The class whose table is at 0x1E1568 (kind 2 of 0x158A80).
struct Object_001E1568 : Object_001E14D8 {
    virtual long __stdcall func_00158A60(unsigned long first, unsigned long second, unsigned long third);  // slot 6, at 0x15C040
};

// Slot 6: locks the buffer (its slot 4), fills it from the arguments with func_0015BE30, or func_0015BF30 when
// +0x110 is set, and unlocks it (slot 5).
long __stdcall Object_001E1568::func_00158A60(unsigned long first, unsigned long second, unsigned long third)
{
    void *data = 0;
    long result = buffer->slot4(&data, 0);

    if (result < 0)
        return result;
    if (value_110 == 0)
        func_0015BE30(data, first, second, third, target, value_10C);
    else
        func_0015BF30(data, first, second, third, target, value_10C);
    buffer->slot5();
    return 0;
}
