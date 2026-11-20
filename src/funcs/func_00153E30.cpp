struct Rect {
    long left;
    long top;
    long right;
    long bottom;
};

// What slot 32 (0x1540A0) passes on: the viewport's rectangle, then slot 31's three values.
struct Desc {
    Rect rect;
    long first;
    float second;
    float third;
};

// A Direct3D 8 viewport (D3DVIEWPORT8: X, Y, Width, Height, MinZ, MaxZ).
struct Viewport {
    long x;
    long y;
    long width;
    long height;
    float min_z;
    float max_z;
};

// The device's viewport (0x264ED0).
extern Viewport data_00264ED0;
extern unsigned long data_00264C1C;

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
    virtual long __stdcall func_00153E30(Desc *desc);  // slot 30
    virtual long __stdcall func_00153FE0(long first, float second, float third);  // slot 31

    char unknown_04[0x3C];
    float value_40;
    float value_44;
    long value_48;
    char unknown_4C[0x24];
    Rect rect;
};

// Slot 30: the viewport covers the description's rectangle, or the device's rectangle at +0x70 without one; then
// slot 31 again with the values the device keeps at +0x48, +0x40 and +0x44.
long __stdcall Object_001E0F00::func_00153E30(Desc *desc)
{
    if (desc) {
        data_00264ED0.x = desc->rect.left;
        data_00264ED0.y = desc->rect.top;
        data_00264ED0.width = desc->rect.right - desc->rect.left;
        data_00264ED0.height = desc->rect.bottom - desc->rect.top;
    } else {
        data_00264ED0.x = 0;
        data_00264ED0.y = 0;
        data_00264ED0.width = rect.right - rect.left;
        data_00264ED0.height = rect.bottom - rect.top;
    }
    data_00264C1C = 0;
    func_0018DAA0(&data_00264ED0);
    return func_00153FE0(value_48, value_40, value_44);
}
