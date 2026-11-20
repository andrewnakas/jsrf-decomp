unsigned int func_0014C690(float value);

// The menu func_0013A340 runs: a pulse level at +0x2b8 moving at the speed at +0x2b4 and the colour it gives.
struct Object_001379E0 {
    char unknown_000[0x2b4];
    float speed;
    float level;
    char unknown_2bc;
    unsigned char red;
    unsigned char green;
    unsigned char blue;

    void func_001394F0();
};

// Moves the level by a thirtieth of the speed, turning the speed around at 1 and at 0, and sets the colour from it:
// red 50 + func_0014C690(110 level), green and blue 50 + func_0014C690(-50 level).
void Object_001379E0::func_001394F0()
{
    level += speed * (1.0f / 30.0f);
    if (speed > 0.0f) {
        if (level >= 1.0f) {
            level = 1.0f;
            speed *= -1.0f;
        }
    } else if (level <= 0.0f) {
        level = 0.0f;
        speed *= -1.0f;
    }
    red = (int)func_0014C690(level * 110.0f) + 50.0f;
    green = (int)func_0014C690(level * -50.0f) + 50.0f;
    blue = (int)func_0014C690(level * -50.0f) + 50.0f;
}
