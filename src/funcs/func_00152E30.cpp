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
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void __stdcall slot3();
    virtual long __stdcall func_00152E30(int index);  // slot 4

    long __stdcall func_00152DE0(unsigned int index);
};

// Clears entry index of the table at 0x264E70 (func_00152DE0), or all of them for -1 (the same code, inline).
long __stdcall Object_001E12F8::func_00152E30(int index)
{
    if (index == -1) {
        for (unsigned int i = 0; i < data_00264E74; i++) {
            if (i < data_00264E74 && data_00264E70[i].state) {
                memset(&data_00264E70[i], 0, sizeof(Entry));
                func_0018DDE0((void *)(i + 1), 0);
            }
        }
        return 0;
    }
    return func_00152DE0(index);
}
