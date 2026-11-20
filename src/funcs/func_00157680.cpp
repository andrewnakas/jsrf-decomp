/* sym: ??0Object_001E141C@@QAE@XZ = 0x00157680 */
extern "C" void *memset(void *destination, int value, unsigned int size);

// The class whose table is at 0x1E141C (12 slots, 0x1040 bytes; constructor 0x157680, Release 0x1579A0, created
// by 0x157710).
struct Object_001E141C {
    virtual long __stdcall func_001577C0(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_001576F0();  // slot 1
    virtual unsigned long __stdcall func_001579A0();  // slot 2
    virtual long __stdcall func_00157800(unsigned long first, unsigned long second, unsigned long third);  // slot 3
    virtual void __stdcall func_00157960();  // slot 4
    virtual long __stdcall func_00157100(unsigned long first, unsigned long second);  // slot 5
    virtual long __stdcall func_001571E0(unsigned long first, unsigned long second);  // slot 6
    virtual long __stdcall func_001572D0();  // slot 7
    virtual long __stdcall func_00157300();  // slot 8
    virtual void __stdcall func_0015A1C0(unsigned long x, unsigned long y, const unsigned short *text);  // slot 9
    virtual long __stdcall func_00157320(unsigned long first, unsigned long second);  // slot 10
    virtual long __stdcall func_001574C0(unsigned long first, unsigned long second, unsigned long third);  // slot 11

    Object_001E141C();
    ~Object_001E141C() {}

    long __stdcall func_00156E70(unsigned long first, unsigned long second, unsigned long third);

    unsigned long buffer[0x404];
    unsigned long value_1014;
    unsigned long value_1018;
    unsigned long value_101C;
    float value_1020;
    unsigned long *aligned;
    unsigned long value_1028[5];
    unsigned long references;
};

// The constructor: clears the buffer and the values and keeps a 16-byte aligned pointer into the buffer.
Object_001E141C::Object_001E141C()
{
    value_1014 = 0;
    value_1018 = 0;
    value_101C = 0;
    value_1020 = 1.0f;
    memset(buffer, 0, sizeof(buffer));
    aligned = (unsigned long *)(((unsigned long)buffer + 15) & ~15);
    value_1028[0] = 0;
    value_1028[1] = 0;
    value_1028[2] = 0;
    value_1028[3] = 0;
    value_1028[4] = 0;
    references = 0;
}
