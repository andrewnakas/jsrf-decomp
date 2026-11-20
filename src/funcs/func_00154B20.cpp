extern "C" void *memset(void *destination, int value, unsigned int size);
int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);
void __stdcall func_0018DF10(unsigned long first, void *second);

extern unsigned char data_00264F50[];
extern void **data_00264F68;
extern void **data_00264F6C;
extern int data_00264F70;
extern unsigned long data_00264F78[0x20];

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
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
    virtual void __stdcall func_0014F6D0(unsigned int index);  // slot 15

    void func_00154B20();
};

// Undoes the table at data_00264F68 when there is one: no texture on stages 0 to 2 (func_0018DF10), slot 15 for
// every entry, the memory freed (func_00145A5D with 0x8000) and the globals around it cleared.
void Object_001E0F00::func_00154B20()
{
    if (data_00264F68) {
        func_0018DF10(0, 0);
        func_0018DF10(1, 0);
        func_0018DF10(2, 0);
        func_0014F6D0(-1);
        func_00145A5D(data_00264F68, 0, 0x8000);
        data_00264F68 = 0;
        data_00264F6C = 0;
        data_00264F70 = 0;
        memset(data_00264F50, 0, 0x16);
        memset(data_00264F78, 0, sizeof(data_00264F78));
    }
}
