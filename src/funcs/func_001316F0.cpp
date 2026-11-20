struct Interface_001316F0 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5();
    virtual long __stdcall slot6();
    virtual long __stdcall slot7(int value);
};

struct Object_00120420 {
    char unknown_000[0xb50];
    Interface_001316F0 *first;
    Interface_001316F0 *second;

    void func_00122300();
    void func_001316F0();
};

// Calls slot 7 of the interfaces at +0xb50 and +0xb54 with 0, then func_00122300.
void Object_00120420::func_001316F0()
{
    first->slot7(0);
    second->slot7(0);
    func_00122300();
}
