struct Interface_00120600 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4(void **data, int first, int second);
    virtual long __stdcall slot5();
};

struct Object_00120420 {
    char unknown_000[0xb50];
    Interface_00120600 *first;

    void func_00120960(int index);
};

extern unsigned int *data_00258C70;
extern void *data_00258C74;
extern void *data_00258C78;
extern unsigned int data_00225BC4[];

// The counterpart of func_00120600: copies the number of words data_00225BC4 gives for an index from
// data_00258C70 back into the data of the interface at +0xb50 (slots 4 and 5), then frees data_00258C70,
// data_00258C74 and data_00258C78.
void Object_00120420::func_00120960(int index)
{
    void *locked;
    first->slot4(&locked, 0, 0);
    unsigned int *data = (unsigned int *)locked;
    for (unsigned int i = 0; i < data_00225BC4[index]; i++) {
        data[i] = data_00258C70[i];
    }
    first->slot5();
    operator delete(data_00258C70);
    operator delete(data_00258C74);
    operator delete(data_00258C78);
}
