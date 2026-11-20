/* const: 0x100000 */

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

    void func_00120600(int index);
};

extern unsigned int *data_00258C70;
extern unsigned int data_00225BC4[];

// Allocates 1 MiB at data_00258C70 and copies into it the number of words data_00225BC4 gives for an index from
// the data of the interface at +0xb50 (through its slots 4 and 5).
void Object_00120420::func_00120600(int index)
{
    void *locked;
    data_00258C70 = (unsigned int *)operator new(0x100000);
    first->slot4(&locked, 0, 0);
    unsigned int *data = (unsigned int *)locked;
    for (unsigned int i = 0; i < data_00225BC4[index]; i++) {
        data_00258C70[i] = data[i];
    }
    first->slot5();
}
