struct Source;

// What the device is set up with (0x38 bytes, kept at +0xA8): the size at +8, the bits per pixel at +0x10 and two
// more words a caller may change.
struct Params {
    unsigned long unknown_00[2];
    unsigned long width;
    unsigned long height;
    unsigned long bits;
    unsigned long value_14;
    unsigned long value_18;
    unsigned long unknown_1C[7];
};

// Set while the device is being set up again.
extern unsigned long data_002650E0;

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014CF20(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0014CF00();  // slot 1
    virtual unsigned long __stdcall func_0014CF80();  // slot 2
    virtual long __stdcall func_00155A60(unsigned long argument1);  // slot 3
    virtual void __stdcall func_00155540(void *handle);  // slot 4
    virtual long __stdcall func_00155560(unsigned long argument1, unsigned long argument2, unsigned long argument3);  // slot 5
    virtual long __stdcall func_00155380(Params *params);  // slot 6
    virtual long __stdcall func_00154D70(int kind, Source *source);  // slot 7
    virtual void *__stdcall func_00154DC0(int kind);  // slot 8
    virtual long __stdcall func_00155150(unsigned long argument1, unsigned long argument2);  // slot 9
    virtual long __stdcall func_00155050(const Params *desc, int again);  // slot 10

    long func_00154D30(const Params *params);
    unsigned long func_001569A0(const Params *params);
    unsigned long func_00156A30(const Params *params, unsigned long format, unsigned long *flag);
    long func_00156AB0(const Params *params, unsigned long flags);
    void func_001541E0(const Params *params);
    long func_00154FD0();

    char unknown_04[0x34];
    unsigned long format;
    unsigned long value_3C;
    char unknown_40[0x40];
    unsigned long value_80;
    char unknown_84[0x24];
    Params params;
};

// Slot 10: takes the device's set-up with the size, depth and the words at +0x14 and +0x18 from desc and either
// shuts the device down and sets it up again from scratch (slot 6, with data_002650E0 set meanwhile) or picks the
// display format again (+0x38, +0x3C) and applies it (func_00156AB0, then func_001541E0). E_FAIL when no format
// fits, E_INVALIDARG without desc.
long __stdcall Object_001E0F00::func_00155050(const Params *desc, int again)
{
    if (desc) {
        Params changed = params;
        changed.width = desc->width;
        changed.height = desc->height;
        changed.bits = desc->bits;
        changed.value_14 = desc->value_14;
        changed.value_18 = desc->value_18;
        if (again) {
            data_002650E0 = 1;
            func_00154FD0();
            long result = func_00155380(&changed);
            data_002650E0 = 0;
            return result;
        }
        func_00154D30(&changed);
        long result = 0x80004005;
        format = func_001569A0(&changed);
        if (format != (unsigned long)-1) {
            value_3C = func_00156A30(&changed, format, &value_80);
            if (value_3C != (unsigned long)-1) {
                result = func_00156AB0(&changed, 0);
                if (result >= 0)
                    func_001541E0(&changed);
            }
        }
        return result;
    }
    return 0x80070057;
}
