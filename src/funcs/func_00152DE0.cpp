extern "C" void *memset(void *destination, int value, unsigned int size);
long __stdcall func_0018DDE0(void *first, unsigned long second);

// An entry of the table at 0x264E70 (0x70 bytes).
struct Entry {
    unsigned long unknown_00;
    unsigned long index;
    unsigned long state;
    char unknown_0C[0x64];
};

extern Entry *data_00264E70;
extern unsigned int data_00264E74;

// A class whose table is at 0x1E12F8 (12 slots).
struct Object_001E12F8 {
    virtual long __stdcall func_00153300(const void *iid, void **object);  // slot 0

    long __stdcall func_00152DE0(unsigned int index);
};

// Clears entry index of the table at 0x264E70 and hands index + 1 and 0 to func_0018DDE0; 1 if the entry is
// unused, E_INVALIDARG past the end.
long __stdcall Object_001E12F8::func_00152DE0(unsigned int index)
{
    if (index < data_00264E74) {
        if (data_00264E70[index].state) {
            memset(&data_00264E70[index], 0, sizeof(Entry));
            return func_0018DDE0((void *)(index + 1), 0);
        }
        return 1;
    }
    return 0x80070057;
}
