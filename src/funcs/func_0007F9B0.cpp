// The player object (func_0008D1E0, func_0009B190 and func_000A20A0 call this with their own `this`): 0x6c is
// the seed, 0xc94 a counter and 0xcd4 a float.
struct Object_000A1C50 {
    char unknown_000[0x6c];
    unsigned int seed;
    char unknown_070[0xc24];
    unsigned int count_c94;
    char unknown_c98[0x3c];
    float value_cd4;

    unsigned int func_0007F9B0(unsigned int range);
};

// A pseudo-random number below the range: steps the seed at +0x6c (times 0x103) and mixes in the counter at
// +0xc94 and the bits of the float at +0xcd4.
unsigned int Object_000A1C50::func_0007F9B0(unsigned int range)
{
    unsigned int value = *(unsigned int *)&value_cd4 + count_c94 + seed;
    seed *= 0x103;
    return value % range;
}
