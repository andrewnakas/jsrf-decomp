// An entry of the 0x70-byte table at data_00264E70.
struct Entry {
    unsigned long enabled;
    unsigned long index;
    unsigned long state;
    char unknown_0C[0x64];
};

extern Entry *data_00264E70;
extern unsigned int data_00264E74;

// A class whose table is at 0x1E12F8 (12 slots).
struct Object_001E12F8 {
    virtual long __stdcall func_00153300(const void *iid, void **object);  // slot 0
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual long __stdcall func_001530F0(unsigned long argument1, unsigned long argument2);  // slot 7

    void __stdcall func_00153080(unsigned int index, int enable);
};

// Slot 7: turns entry index on or off (func_00153080), or every entry with a state for -1. E_INVALIDARG for an
// index past the table or an entry without a state.
long __stdcall Object_001E12F8::func_001530F0(unsigned long argument1, unsigned long argument2)
{
    if (argument1 == (unsigned long)-1) {
        for (unsigned int i = 0; i < data_00264E74; i++) {
            if (data_00264E70[i].state)
                func_00153080(i, argument2);
        }
        return 0;
    }
    if (argument1 < data_00264E74 && data_00264E70[argument1].state) {
        func_00153080(argument1, argument2);
        return 0;
    }
    return 0x80070057;
}
