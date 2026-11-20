extern "C" void *memset(void *destination, int value, unsigned int size);

// A display mode (D3DDISPLAYMODE: Width, Height, RefreshRate, Flags, Format).
struct DisplayMode {
    unsigned long width;
    unsigned long height;
    unsigned long refresh;
    unsigned long flags;
    unsigned long format;
};

// Direct3D 8's GetAdapterModeCount (adapter) and EnumAdapterModes (adapter, mode index, mode).
unsigned int __stdcall func_00199830(unsigned int adapter);
long __stdcall func_001998D0(unsigned int adapter, unsigned int index, DisplayMode *mode);

// What the device is set up with: the size at +8 and the bits per pixel at +0x10.
struct Params {
    unsigned long unknown_00[2];
    unsigned long width;
    unsigned long height;
    unsigned long bits;
};

// The Direct3D device wrapper (table 0x1E0F00).
struct Object_001E0F00 {
    unsigned long func_001569A0(const Params *params);
};

// The format of the first display mode of adapter 0 with the size and depth asked for (0x1E for 32 bits, 0x11 or
// 0x1C for 16); -1 when there is none.
unsigned long Object_001E0F00::func_001569A0(const Params *params)
{
    unsigned int count = func_00199830(0);
    for (unsigned int i = 0; i < count; i++) {
        DisplayMode mode;
        memset(&mode, 0, sizeof(mode));
        if (func_001998D0(0, i, &mode) >= 0 && mode.width == params->width && mode.height == params->height) {
            if (params->bits == 32) {
                if (mode.format != 0x1e)
                    continue;
            } else if (params->bits == 16) {
                if (mode.format != 0x11 && mode.format != 0x1c)
                    continue;
            } else {
                continue;
            }
            return mode.format;
        }
    }
    return (unsigned long)-1;
}
