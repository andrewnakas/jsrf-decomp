float func_0014C870(float value, float limit);
float func_0004A8A0(float current, float target, float rate);

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0xb90];
    float value_b90;
    char unknown_b94[0x58c];
    int value_1120;

    void func_000987A0();
};

// Moves 0xb90 toward the size of 0x1120 over 16384 (func_0014C870 with 1), at a rate of 1/60 (func_0004A8A0).
void Object_000A1C50::func_000987A0()
{
    float size;
    float target;
    if (value_1120 < 0) {
        size = value_1120 * -0.00006103515625f;
    } else {
        size = value_1120 * 0.00006103515625f;
    }
    target = func_0014C870(size, 1.0f);
    value_b90 = func_0004A8A0(value_b90, target, 0.016666668f);
}
