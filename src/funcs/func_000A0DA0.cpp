// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x12c];
    float value_12c;
    char unknown_130[0xba4];
    float value_cd4;

    void func_000A0DA0();
};

void Object_000A1C50::func_000A0DA0()
{
    float old = value_cd4;
    float speed = value_12c + value_cd4;
    value_cd4 = speed;
    if (speed <= 0.0f && old > 0.0f || speed >= 0.0f && old < 0.0f) {
        value_cd4 = 0.0f;
        value_12c = 0.0f;
    }
}
