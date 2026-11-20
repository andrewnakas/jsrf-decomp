struct Object_0007FCC0 {
    char unknown_000[0xfec];
    int unknown_fec;
    int unknown_ff0;
    int unknown_ff4;

    int func_0007FCC0();
};

// Counts which of the three words at +0xfec, +0xff0 and +0xff4 are set.
int Object_0007FCC0::func_0007FCC0()
{
    int count = 0;
    if (unknown_fec) {
        count = 1;
    }
    if (unknown_ff0) {
        count++;
    }
    if (unknown_ff4) {
        count++;
    }
    return count;
}
