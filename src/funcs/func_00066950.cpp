struct Object_00066980 {
    unsigned int value;

    float func_00066950();
};

// Steps the 15-bit pseudo-random value and returns it as a fraction of 32768.
float Object_00066980::func_00066950()
{
    value = (value * 0x8d + 0x3cb) & 0x7fff;
    return value * 3.0517578e-05f;
}
