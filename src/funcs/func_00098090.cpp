// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x1120];
    int value_1120;

    float func_00098090();
};

// The value at 0x1120 as -1 to 1: 0 within 0x38e of 0, then scaled by 6.462871e-05 per unit beyond that, and -1 or 1
// beyond 0x4000.
float Object_000A1C50::func_00098090()
{
    int value = value_1120;
    if (value < -0x38e) {
        if (value < -0x4000) {
            return -1.0f;
        }
        return (value + 0x38e) * 6.462871e-05f;
    }
    if (value > 0x38e) {
        if (value > 0x4000) {
            return 1.0f;
        }
        return (value - 0x38e) * 6.462871e-05f;
    }
    return 0.0f;
}
