struct Rect;
struct Description;

// What the device is set up with (0x38 bytes, kept at +0xA8): the word at +4, the size at +8 and the rest.
struct Params {
    unsigned long unknown_00;
    unsigned long value_04;
    unsigned long width;
    unsigned long height;
    unsigned long unknown_10[10];
};

int __stdcall func_00182B81(Rect *rect, long left, long top, long right, long bottom);
unsigned long __stdcall func_00199820(unsigned int version);

// Direct3D's state: data_002650DC is set while the device is running, data_002650E0 while it is being set up
// again.
extern unsigned long data_002650DC;
extern unsigned long data_002650E0;

struct Rect {
    long left;
    long top;
    long right;
    long bottom;
};

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014CF20(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0014CF00();  // slot 1
    virtual unsigned long __stdcall func_0014CF80();  // slot 2
    virtual long __stdcall func_00155A60(unsigned long argument1);  // slot 3
    virtual void __stdcall func_00155540(void *handle);  // slot 4
    virtual long __stdcall func_00155560(unsigned long argument1, unsigned long argument2, unsigned long argument3);  // slot 5
    virtual long __stdcall func_00155380(Params *params);  // slot 6

    long func_00154E00(const Description *description);
    unsigned long func_001569A0(const Params *params);
    unsigned long func_00156A30(const Params *params, unsigned long format, unsigned long *flag);
    long func_001549A0(const Params *params, unsigned long format);
    long func_00150EE0(const Params *params);
    long func_00156AB0(const Params *params, unsigned long flags);
    long func_00154E40(void *parameters);
    long func_001564B0(const Params *params);
    void func_001541E0(const Params *params);
    long func_0014FC20(const Params *params);
    long func_0014D9B0(void *parameters);
    long func_00152170(void *parameters);
    void func_00154C20();
    long func_00154FD0();

    char unknown_04[0x28];
    unsigned long value_2C;
    unsigned long width;
    unsigned long height;
    unsigned long format;
    unsigned long value_3C;
    char unknown_40[0x30];
    Rect rect;
    unsigned long value_80;
    char unknown_84[0x24];
    Params params;
};

// The device in use (set here).
extern Object_001E0F00 *data_002650D8;

// Slot 6: sets the device up from params. Keeps the size (and the rectangle 0,0 to it) and a copy of params, then
// starts Direct3D (func_00154E00), picks the display format (+0x38) and its partner (+0x3C), and sets up the parts
// one after another; on any failure the device is shut down again (func_00154FD0) and data_002650E0 cleared.
// 0x800401F1 while Direct3D is already running and not being set up again, E_INVALIDARG without params.
long __stdcall Object_001E0F00::func_00155380(Params *params)
{
    if (data_002650DC && !data_002650E0)
        return 0x800401F1;
    if (params) {
        value_2C = params->value_04;
        width = params->width;
        height = params->height;
        func_00182B81(&rect, 0, 0, width, height);
        unsigned long again = data_002650E0;
        this->params = *params;
        long result = 0x80004005;
        if (!again) {
            result = func_00154E00((const Description *)params);
            if (result >= 0) {
                data_002650DC = func_00199820(0);
                result = 0x80004005;
                data_002650D8 = this;
                format = func_001569A0(params);
                if (format != (unsigned long)-1) {
                    value_3C = func_00156A30(params, format, &value_80);
                    if (value_3C != (unsigned long)-1) {
                        result = func_001549A0(params, format);
                        if (result >= 0) {
                            result = func_00150EE0(params);
                            if (result >= 0) {
                                result = func_00156AB0(params, 1);
                                if (result >= 0) {
                                    result = func_00154E40(params);
                                    if (result >= 0) {
                                        result = func_001564B0(params);
                                        if (result >= 0) {
                                            func_001541E0(params);
                                            func_0014FC20(params);
                                            func_0014D9B0(params);
                                            func_00152170(params);
                                            func_00154C20();
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        data_002650E0 = 0;
        func_00154FD0();
        return result;
    }
    return 0x80070057;
}
