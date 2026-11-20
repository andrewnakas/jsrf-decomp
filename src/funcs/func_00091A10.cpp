// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0xabc];
    float step;
    char unknown_ac0[0x21c];
    int value_cdc;

    void func_00091A10(float distance, unsigned int frames);
};

// Spreads the distance over the frames as an accelerating ramp: the step at 0xabc is the distance over
// 1 + 2 + ... + frames, and 0xcdc is cleared.
void Object_000A1C50::func_00091A10(float distance, unsigned int frames)
{
    unsigned int sum = 0;
    for (unsigned int i = 0; i < frames; i++) {
        sum += i + 1;
    }
    step = distance / sum;
    value_cdc = 0;
}
