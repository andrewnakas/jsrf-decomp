// The player (table 0x1CCFF8).
struct Object_000A1C50 {
    char unknown_0000[0x10f4];
    int mode;
    int unknown_10f8;
    int unknown_10fc;
    float unknown_1100;
    float unknown_1104;

    void func_0007FFB0(int first, float value, int second);
};

// Reached from 0x80110 (a jump on the player its owner names): mode 0xc3 at +0x10f4 with the three arguments at
// +0x10f8..+0x1100, and +0x1104 set to 1.0 unless `value` is positive.
void Object_000A1C50::func_0007FFB0(int first, float value, int second)
{
    mode = 0xc3;
    unknown_10fc = second;
    unknown_1100 = value;
    if (value > 0.0f) {
        unknown_1104 = 0.0f;
    } else {
        unknown_1104 = 1.0f;
    }
    unknown_10f8 = first;
}
