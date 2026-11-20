// A surface description (D3DSURFACE_DESC on this platform: format, type, usage, size, multisample type, width,
// height).
struct SurfaceDesc {
    unsigned long format;
    unsigned long type;
    unsigned long usage;
    unsigned long size;
    unsigned long multisample;
    unsigned long width;
    unsigned long height;
};

// Direct3D 8's GetBackBuffer (index, type, surface) and GetDesc; the reference release and a push-buffer
// flush with its flags.
long __stdcall func_0018D620(int index, unsigned long type, void **surface);
long __stdcall func_0018E730(void *surface, SurfaceDesc *desc);
unsigned long __stdcall func_00192990(void *object);
unsigned long __stdcall func_00198F10(unsigned long flags);

extern unsigned long data_00264C1C;

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014D110(unsigned long *size, unsigned long argument2);  // slot 119

    void func_00154C30();
    void func_00154AE0();
    void func_00154C20();
    int func_00154930(void *resource);
};

// Slot 119: counts the frame (func_00154C30), passes null for 0 to 2 to func_0018DF10 (func_00154AE0), checks
// that both back buffers (0 and -1) exist and, given a destination, writes the first one's width, height and
// format index there. E_FAIL (after func_00198F10 and func_00154C20) when a buffer is missing.
long __stdcall Object_001E0F00::func_0014D110(unsigned long *size, unsigned long argument2)
{
    func_00154C30();
    func_00154AE0();
    data_00264C1C = 0;
    void *surface = 0;
    func_0018D620(0, 0, &surface);
    if (surface) {
        func_00192990(surface);
        func_00198F10(2);
        void *back = 0;
        func_0018D620(-1, 0, &back);
        if (back) {
            func_00192990(back);
            if (size) {
                SurfaceDesc desc;
                func_0018E730(surface, &desc);
                size[0] = desc.width;
                size[1] = desc.height;
                size[2] = func_00154930((void *)desc.format);
            }
            return 0;
        }
        func_00198F10(4);
    } else {
        func_00198F10(0);
    }
    func_00154C20();
    return 0x80004005;
}
