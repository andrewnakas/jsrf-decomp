int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

// The Direct3D device wrapper (table 0x1E0F00); data_002650D8 points at the one in use.
struct Object_001E0F00 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8();
    virtual void __stdcall slot9();
    virtual void __stdcall slot10();
    virtual void __stdcall slot11();
    virtual void __stdcall slot12();
    virtual void __stdcall slot13();
    virtual void __stdcall slot14();
    virtual void __stdcall slot15(unsigned int index);

    long func_00154F80(void *resource);
};

extern Object_001E0F00 *data_002650D8;

// A class whose table is at 0x1E1248 (9 slots; Release 0x151C40, created by 0x151CA0).
struct Object_001E1248 {
    virtual long __stdcall func_00151AC0(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0014D4A0_1();  // slot 1: AddRef, folded
    virtual unsigned long __stdcall func_00151C40();  // slot 2
    virtual void __stdcall func_00151820(int level, unsigned long color);  // slot 3
    virtual long __stdcall func_00151840(unsigned long x, unsigned long y, const char *text);  // slot 4
    virtual long __stdcall func_001519D0(unsigned long x, unsigned long y, int number);  // slot 5
    virtual long __stdcall func_00151A00(unsigned long x, unsigned long y, unsigned long value);  // slot 6
    virtual long __stdcall func_00151A30(unsigned long x, unsigned long y, float value);  // slot 7
    virtual long func_00151A90(unsigned long x, unsigned long y, const char *format, ...);  // slot 8

    ~Object_001E1248() {}

    char unknown_04[0x10];
    void *memory;
    unsigned int index;
    char unknown_1C[4];
    unsigned long references;
};

// Release: the last reference hands the index at +0x18 to the device's slot 15, frees the memory at +0x14
// (func_00145A5D with 0x8000), takes the object off the device's list and deletes it.
unsigned long __stdcall Object_001E1248::func_00151C40()
{
    if (--references == 0) {
        data_002650D8->slot15(index);
        if (memory) {
            func_00145A5D(memory, 0, 0x8000);
            memory = 0;
        }
        data_002650D8->func_00154F80(this);
        delete this;
        return 0;
    }
    return references;
}
