// Gets a back buffer (Direct3D 8's GetBackBuffer: index, type, surface).
long __stdcall func_0018D620(int index, unsigned long type, void **surface);
unsigned long __stdcall func_00192950(void *object);
unsigned long __stdcall func_00192990(void *object);

// The Direct3D device wrapper (table 0x1E0F00); data_002650D8 points at the one in use.
struct Object_001E0F00 {
    int func_00154930(void *resource);
    long func_00154EE0(void *resource);

    char unknown_00[0x30];
    unsigned long value_30;
    unsigned long value_34;
    void *value_38;
};

extern Object_001E0F00 *data_002650D8;

// Kind 3 of 0x152BC0 (table 0x1E12D8, 0x18 bytes).
struct Object_001E12D8 {
    virtual long __stdcall func_00152360(const void *iid, void **object);  // slot 0

    long func_00152A60();

    void *object;
    unsigned long value_08;
    unsigned long value_0C;
    long value_10;
};

// Sets kind 3 up: copies the device's values at +0x30 and +0x34, keeps func_00154930 of its value at +0x38, takes
// back buffer 0 (dropping the extra reference when it has two or more) and puts this on the device's list.
long Object_001E12D8::func_00152A60()
{
    value_08 = data_002650D8->value_30;
    value_0C = data_002650D8->value_34;
    value_10 = data_002650D8->func_00154930(data_002650D8->value_38);
    void *surface = 0;
    func_0018D620(0, 0, &surface);
    if (func_00192950(surface) >= 2)
        func_00192990(surface);
    object = surface;
    data_002650D8->func_00154EE0(this);
    return 0;
}
