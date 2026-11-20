struct Object_00066980 {
    unsigned int value;

    unsigned int func_00066930();
};

// Steps the 15-bit pseudo-random value (func_00066980 seeds it) and returns it; the caller at 0xc374d divides
// the result by 3 unsigned (div).
unsigned int Object_00066980::func_00066930()
{
    value = (value * 0x8d + 0x3cb) & 0x7fff;
    return value;
}
