struct Interface {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual unsigned int __stdcall slot3(int what);
};

struct Sound {
    Interface *format;
    void *data;
    unsigned long value_08;
    unsigned int count;
};

long __stdcall func_00145A99(void *first, unsigned long second, unsigned long third, unsigned long *result);

// A class whose table is at 0x1E1640 (26 slots; Release 0x159D40, created by 0x159D70).
struct Object_001E1640 {
    virtual long __stdcall func_00159C90(Sound *sound, void **data, unsigned int *frame,
                                         unsigned long *value);  // slot 10
};

// Slot 10, the counterpart of slot 11: hands out the sound's data, the format's slot 3 value for 3 and the word at
// +8 (each where asked) and calls func_00145A99 on the data with its count times that value, and 4. E_FAIL for no
// data.
long __stdcall Object_001E1640::func_00159C90(Sound *sound, void **data, unsigned int *frame, unsigned long *value)
{
    void *memory = sound->data;
    if (memory) {
        unsigned int size = sound->format->slot3(3);
        if (data)
            *data = memory;
        if (frame)
            *frame = size;
        if (value)
            *value = sound->value_08;
        unsigned long result = 0;
        func_00145A99(memory, sound->count * size, 4, &result);
        return 0;
    }
    return 0x80004005;
}
