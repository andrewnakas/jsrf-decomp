/* sym: ?func_00158A60@Object_001E1538@@UAGJKKK@Z = 0x0015BC20 */
struct Buffer {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual long __stdcall slot4(void **data, unsigned long flags);
    virtual long __stdcall slot5();
};

// The four ways kind 1 fills the buffer from count entries spaced stride apart (SSE code).
void func_0015B9E0(void *destination, unsigned long source, unsigned long count, unsigned long stride,
                   const unsigned long *target, float scale);
void func_0015BA70(void *destination, unsigned long source, unsigned long count, unsigned long stride,
                   const unsigned long *target, float scale);
void func_0015BB00(void *destination, unsigned long source, unsigned long count, unsigned long stride,
                   const unsigned long *target, float scale);
void func_0015BB90(void *destination, unsigned long source, unsigned long count, unsigned long stride,
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
    unsigned long value_118[4];
};

// The class whose table is at 0x1E1568 (kind 1 of 0x158A80).
struct Object_001E1538 : Object_001E14D8 {
    virtual long __stdcall func_00158A60(unsigned long first, unsigned long second, unsigned long third);  // slot 6, at 0x15BC20

    unsigned long value_128;
};

// Slot 6: locks the buffer (its slot 4), fills it from the arguments with one of four functions chosen by +0x110
// and by whether +0x128 is 1, and unlocks it (slot 5).
long __stdcall Object_001E1538::func_00158A60(unsigned long first, unsigned long second, unsigned long third)
{
    void *data = 0;
    long result = buffer->slot4(&data, 0);

    if (result < 0)
        return result;
    if (value_110 == 0) {
        if (value_128 == 1)
            func_0015BA70(data, first, second, third, target, value_10C);
        else
            func_0015B9E0(data, first, second, third, target, value_10C);
    } else {
        if (value_128 == 1)
            func_0015BB90(data, first, second, third, target, value_10C);
        else
            func_0015BB00(data, first, second, third, target, value_10C);
    }
    buffer->slot5();
    return 0;
}
