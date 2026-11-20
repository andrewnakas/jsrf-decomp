struct Rect {
    long left;
    long top;
    long right;
    long bottom;
};

// What the device keeps at +0xA8 (0x38 bytes).
struct Params {
    unsigned long value_00;
    unsigned long value_04;
    long width;
    long height;
    char unknown_10[0x28];
};

int __stdcall func_00182B81(Rect *rect, long left, long top, long right, long bottom);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014CF20(const void *iid, void **object);  // slot 0

    long func_00154D30(const Params *mode);

    char unknown_04[0x28];
    unsigned long value_2C;
    long width;
    long height;
    char unknown_38[0x38];
    Rect rect;
    char unknown_80[0x28];
    Params mode;
};

// Keeps the mode (and its value at +4, width and height), and makes the rectangle at +0x70 (0, 0, width, height).
long Object_001E0F00::func_00154D30(const Params *mode)
{
    value_2C = mode->value_04;
    width = mode->width;
    height = mode->height;
    func_00182B81(&rect, 0, 0, width, height);
    this->mode = *mode;
    return 0;
}
