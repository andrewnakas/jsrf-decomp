// What the caller passes: the width and height at +8.
struct Size {
    unsigned long unknown_00[2];
    unsigned long width;
    unsigned long height;
};

// A Direct3D 8 viewport (D3DVIEWPORT8: X, Y, Width, Height, MinZ, MaxZ).
struct Viewport {
    unsigned long x;
    unsigned long y;
    unsigned long width;
    unsigned long height;
    float min_z;
    float max_z;
};

// The device's viewport (0x264ED0).
extern Viewport data_00264ED0;

// Sets the viewport (Direct3D 8's SetViewport).
long __stdcall func_0018DAA0(const Viewport *viewport);

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
    virtual void __stdcall slot30();
    virtual long __stdcall func_00153FE0(long first, float second, float third);  // slot 31

    void func_001541E0(const Size *size);

    char unknown_04[0x48];
    unsigned long value_4C[5];
    float value_60;
};

// Sets the viewport to the whole of the given size with depths 0 to 1, clears +0x4C, sets +0x60 to 1 and puts
// slot 31 back to its defaults (0x4000, 0.5, 500).
void Object_001E0F00::func_001541E0(const Size *size)
{
    data_00264ED0.x = 0;
    data_00264ED0.y = 0;
    data_00264ED0.width = size->width;
    data_00264ED0.height = size->height;
    data_00264ED0.min_z = 0.0f;
    data_00264ED0.max_z = 1.0f;
    value_4C[0] = 0;
    value_60 = 1.0f;
    func_0018DAA0(&data_00264ED0);
    func_00153FE0(0x4000, 0.5f, 500.0f);
}
