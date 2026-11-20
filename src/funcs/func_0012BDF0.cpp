struct Interface_0012BDF0 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

struct Object_00120420 {
    char unknown_000[0x8b0];
    int id;

    void func_0012BDF0();
};

extern Interface_0012BDF0 *data_002590D0;
extern void *data_00259008;

// Clears the interface at data_002590D0, the id at +0x8b0 (-1) and the buffer at data_00259008.
void Object_00120420::func_0012BDF0()
{
    data_002590D0 = 0;
    id = -1;
    data_00259008 = 0;
}
