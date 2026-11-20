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
};

struct Object_00047470 {
    virtual ~Object_00047470();

    Surface_000476F0 *surface;

    void func_000476F0(int argument);
};

// Stored at +0x64 by the constructor (0x48100) and called through that pointer (0x47938): passes its
// argument to slot 16 of the interface at +0x4.
void Object_00047470::func_000476F0(int argument)
{
    surface->slot16(argument);
}
