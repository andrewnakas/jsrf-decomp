// What the device's slot 6 starts it with (built by 0x5F350).
struct Params_0005F2C0;

// The device (class 0x1E0F00): slot 2 releases it, slot 6 starts it.
struct Device_00251D6C {
    virtual long __stdcall slot0();
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall Release();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual long __stdcall slot6(Params_0005F2C0 *params);
};

long __stdcall func_0014CFB0(void **object);

// Creates the device (func_0014CFB0) and starts it with the parameters (its slot 6) into *device; on failure releases
// it completely, clears *device and returns the error.
long __stdcall func_0005F2C0(Params_0005F2C0 *params, Device_00251D6C **device)
{
    Device_00251D6C *created = 0;
    long result = func_0014CFB0((void **)&created);
    if (result >= 0) {
        result = created->slot6(params);
        if (result >= 0) {
            *device = created;
            return 0;
        }
        while (created->Release()) {
        }
        *device = 0;
        return result;
    }
    *device = 0;
    return result;
}
