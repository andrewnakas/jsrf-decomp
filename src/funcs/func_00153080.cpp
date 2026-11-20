long __stdcall func_0018DDE0(void *first, unsigned long second);

// An entry of the 0x70-byte table at data_00264E70.
struct Entry {
    unsigned long enabled;
    unsigned long index;
    unsigned long state;
    char unknown_0C[0x64];
};

extern Entry *data_00264E70;

// A class whose table is at 0x1E12F8 (12 slots).
struct Object_001E12F8 {
    virtual long __stdcall func_00153300(const void *iid, void **object);  // slot 0

    void __stdcall func_00153080(unsigned int index, int enable);
};

// Turns entry index on or off: hands index + 1 and the new state to func_0018DDE0 when it changes and keeps it
// when that works (called by slot 7, 0x1530F0).
void __stdcall Object_001E12F8::func_00153080(unsigned int index, int enable)
{
    if (enable) {
        if (data_00264E70[index].enabled == 0 && func_0018DDE0((void *)(index + 1), 1) >= 0)
            data_00264E70[index].enabled = 1;
    } else {
        if (data_00264E70[index].enabled != 0 && func_0018DDE0((void *)(index + 1), 0) >= 0)
            data_00264E70[index].enabled = 0;
    }
}
