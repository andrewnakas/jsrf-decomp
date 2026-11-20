struct Interface_00120510 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

struct Object_0006E130 {
    void func_0006E7B0(int id);
};

struct Object_00120420 {
    char unknown_000[0x904];
    int ids[2];
    char unknown_90c[0x254];
    void *buffers[2];

    void func_00120510();
};

extern Object_0006E130 data_00252790;
extern Interface_00120510 *data_00258C68;
extern Interface_00120510 *data_00258C6C;

// Releases the two ids at +0x904 (through func_0006E7B0 of data_00252790) with their buffers, then slot 2 of
// the interfaces at data_00258C68 and data_00258C6C.
void Object_00120420::func_00120510()
{
    if (ids[1] != -1) {
        data_00252790.func_0006E7B0(ids[1]);
        operator delete(buffers[1]);
        ids[1] = -1;
    }
    if (ids[0] != -1) {
        data_00252790.func_0006E7B0(ids[0]);
        operator delete(buffers[0]);
        ids[0] = -1;
    }
    if (data_00258C68) {
        data_00258C68->slot2();
        data_00258C68 = 0;
    }
    if (data_00258C6C) {
        data_00258C6C->slot2();
        data_00258C6C = 0;
    }
}
