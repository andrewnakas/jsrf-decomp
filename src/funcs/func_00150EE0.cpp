extern "C" void *memset(void *destination, int value, unsigned int size);
void *__stdcall func_00145A2F(void *address, unsigned long size, unsigned long type, unsigned long protect);

// One of the device's 0x50-byte entries.
struct Entry_50 {
    unsigned char bytes[0x50];
};

extern Entry_50 *data_00264D4C;
extern unsigned int data_00264D50;

struct Params {
    unsigned long unknown_00[11];
    unsigned int count;
};

// The Direct3D device wrapper: table 0x1E0F00 (121 slots).
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
    virtual void __stdcall slot15();
    virtual void __stdcall slot16();
    virtual long __stdcall func_00150C00(int index);  // slot 17

    long func_00150EE0(const Params *params);
};

// Makes the table of params->count cleared 0x50-byte entries at data_00264D4C (func_00145A2F) and runs slot 17 with
// -1; E_OUTOFMEMORY when the allocation fails. With no entries, clears the table and returns 1.
long Object_001E0F00::func_00150EE0(const Params *params)
{
    if (params->count) {
        unsigned int size = params->count * sizeof(Entry_50);
        void *memory = func_00145A2F(0, size, 0x3000, 4);
        if (memory) {
            memset(memory, 0, size);
            data_00264D4C = (Entry_50 *)memory;
            data_00264D50 = params->count;
            func_00150C00(-1);
            return 0;
        }
        return 0x8007000e;
    }
    data_00264D4C = 0;
    data_00264D50 = 0;
    return 1;
}
