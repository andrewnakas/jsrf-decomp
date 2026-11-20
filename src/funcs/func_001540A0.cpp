struct Desc {
    char unknown_00[0x10];
    unsigned long first;
    unsigned long second;
    unsigned long third;
};

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
    virtual void __stdcall slot15();
    virtual void __stdcall slot16();
    virtual void __stdcall slot17();
    virtual void __stdcall slot18();
    virtual void __stdcall slot19();
    virtual void __stdcall slot20();
    virtual void __stdcall slot21();
    virtual void __stdcall slot22();
    virtual void __stdcall slot23();
    virtual void __stdcall slot24();
    virtual void __stdcall slot25();
    virtual void __stdcall slot26();
    virtual void __stdcall slot27();
    virtual void __stdcall slot28();
    virtual void __stdcall slot29();
    virtual long __stdcall func_00153E30(Desc *desc);  // slot 30
    virtual long __stdcall func_00153FE0(unsigned long first, unsigned long second, unsigned long third);  // slot 31
    virtual long __stdcall func_001540A0(Desc *desc);  // slot 32
};

// Slot 30 with the description, then, if that succeeded, slot 31 with its three words at +0x10.
long __stdcall Object_001E0F00::func_001540A0(Desc *desc)
{
    long result = func_00153E30(desc);
    if (result >= 0)
        result = func_00153FE0(desc->first, desc->second, desc->third);
    return result;
}
