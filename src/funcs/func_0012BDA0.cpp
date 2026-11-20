struct Interface_0012BDF0 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

struct Object_0006E130 {
    void func_0006E7B0(int id);
};

struct Object_00120420 {
    char unknown_000[0x8b0];
    int id;

    void func_0012BDA0();
};

extern Interface_0012BDF0 *data_002590D0;
extern void *data_00259008;
extern Object_0006E130 data_00252790;

// Releases what func_0012BDF0 cleared: slot 2 of the interface at data_002590D0, the id at +0x8b0 through
// func_0006E7B0 of data_00252790, and the buffer at data_00259008.
void Object_00120420::func_0012BDA0()
{
    if (data_002590D0) {
        data_002590D0->slot2();
        data_002590D0 = 0;
    }
    if (id != -1) {
        data_00252790.func_0006E7B0(id);
    }
    if (data_00259008) {
        operator delete(data_00259008);
        data_00259008 = 0;
    }
}
