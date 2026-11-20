// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0xab8];
    float rise;
    float fall;
    char unknown_ac0[0x14];
    unsigned int frames;
    int frame;
    char unknown_adc[0x200];
    float value_cdc;

    void func_00099D80(float height, unsigned int up, unsigned int down);
};

// Plans a jump of the height over up frames rising and down frames falling: each step grows by the height over the
// sum 1 + 2 + ... of its frames (0xab8 rising, 0xabc falling), 0xcdc starts at up steps, 0xad4 counts all frames and
// 0xad8 starts at 0.
void Object_000A1C50::func_00099D80(float height, unsigned int up, unsigned int down)
{
    unsigned int sum = 0;
    for (unsigned int i = 0; i < up; i++) {
        sum += i + 1;
    }
    rise = height / sum;
    value_cdc = up * rise;
    sum = 0;
    for (unsigned int j = 0; j < down; j++) {
        sum += j + 1;
    }
    fall = height / sum;
    frames = up + down;
    frame = 0;
}
