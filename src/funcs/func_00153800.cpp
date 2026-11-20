long __stdcall func_00199B70(const unsigned long *data, void **result);

// A class whose table is at 0x1E1328 (6 slots; Release 0x153850, created by 0x1539B0).
struct Object_001E1328 {
    virtual long __stdcall func_001537C0(const void *iid, void **object);  // slot 0

    long func_00153800(void **out, const unsigned long *data);
};

// Data that starts with "PSB0" goes to func_00199B70, whose result is given back; E_FAIL for other data,
// E_INVALIDARG without data.
long Object_001E1328::func_00153800(void **out, const unsigned long *data)
{
    long result = 0x80070057;

    if (data) {
        void *object = 0;
        if (data[0] == 0x30425350) {
            func_00199B70(data + 1, &object);
            result = 0;
            *out = object;
        } else
            result = 0x80004005;
    }
    return result;
}
