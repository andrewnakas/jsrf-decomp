struct Surface_000476F0 {
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
    virtual void __stdcall slot16(int argument);
    virtual void __stdcall slot17();
    virtual void __stdcall slot18();
    virtual void __stdcall slot19();
    virtual void __stdcall slot20();
    virtual void __stdcall slot21();
    virtual void __stdcall slot22(int first, int second, int third);
};

struct Object_00048100 {
    virtual ~Object_00048100();

    Surface_000476F0 *surface;

    void func_00047710(int first, int second, int third);
};

// Stored at +0x68 by the constructor func_00048100 and called through that pointer: passes its three arguments
// to slot 22 of the interface at +0x4.
void Object_00048100::func_00047710(int first, int second, int third)
{
    surface->slot22(first, second, third);
}
