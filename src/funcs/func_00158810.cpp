// The base of the classes whose tables are at 0x1E14D8, 0x1E1508, 0x1E1538 and 0x1E1568 (created by 0x158A80).
struct Object_001E14D8 {
    virtual void __stdcall func_00158810(const unsigned long *values, unsigned long second);  // slot 9

    char unknown_04[0x10C];
    unsigned long value_110;
    unsigned long *target;
};

// Slot 9: copies eight words into the target block, or without a source sets it to 0, 0, 1.0, 0, 0, 1.0, 1.0,
// 1.0; keeps second at +0x110.
void __stdcall Object_001E14D8::func_00158810(const unsigned long *values, unsigned long second)
{
    if (values) {
        target[0] = values[0];
        target[1] = values[1];
        target[2] = values[2];
        target[3] = values[3];
        target[4] = values[4];
        target[5] = values[5];
        target[6] = values[6];
        target[7] = values[7];
    } else {
        target[0] = 0;
        target[1] = 0;
        target[2] = 0x3F800000;
        target[3] = 0;
        target[4] = 0;
        target[5] = 0x3F800000;
        target[6] = 0x3F800000;
        target[7] = 0x3F800000;
    }
    value_110 = second;
}
