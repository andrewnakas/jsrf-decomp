struct Interface {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual unsigned int __stdcall slot3(int what);
};

struct Sound {
    Interface *format;
    void *data;
    char unknown_08[4];
    unsigned int count;
};

long __stdcall func_00145A99(void *first, unsigned long second, unsigned long third, unsigned long *result);

// A class whose table is at 0x1E1640 (26 slots; Release 0x159D40, created by 0x159D70).
struct Object_001E1640 {
    virtual long __stdcall func_00159D00(Sound *sound);  // slot 11
};

// func_00145A99 on the sound's data with its count times the format's slot 3 value for 3, and 2.
long __stdcall Object_001E1640::func_00159D00(Sound *sound)
{
    void *data = sound->data;
    unsigned int frame = sound->format->slot3(3);
    unsigned long result = 0;
    unsigned long size = sound->count * frame;
    return func_00145A99(data, size, 2, &result);
}
