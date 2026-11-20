struct Object_0007F9B0 {
    char unknown_000[0x6c];
    unsigned int seed;
    char unknown_070[0xc24];
    unsigned int unknown_c94;
    char unknown_c98[0x3c];
    unsigned int unknown_cd4;

    unsigned int func_0007F9B0(unsigned int range);
};

// A pseudo-random number below the range: steps the seed at +0x6c (times 0x103) and mixes in two counters.
unsigned int Object_0007F9B0::func_0007F9B0(unsigned int range)
{
    unsigned int value = unknown_cd4 + unknown_c94 + seed;
    seed *= 0x103;
    return value % range;
}
