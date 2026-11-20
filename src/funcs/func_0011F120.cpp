struct Object_0011EDA0 {
    char unknown_00[0x6c];
    unsigned int frames;
    unsigned int minutes;
    unsigned int seconds;
    unsigned int hundredths;

    void func_0011F120();
};

unsigned int func_0014C6A0(float value);

// Splits frames (60 per second, clamped to 0..3600 seconds) into minutes, seconds and hundredths.
void Object_0011EDA0::func_0011F120()
{
    float time = frames * (1.0f / 60.0f);
    if (time < 0.0f) {
        time = 0.0f;
    } else if (time > 3600.0f) {
        time = 3600.0f;
    }
    unsigned int whole = func_0014C6A0(time);
    minutes = whole / 60;
    seconds = whole % 60;
    hundredths = func_0014C6A0((time - whole) * 100.0f);
}
