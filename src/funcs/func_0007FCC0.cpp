// The player object: func_000A0F10 calls this with its own `this`, and func_000A07C0 compares the count
// unsigned (`cmp eax, 3; jb`).
struct Object_000A1C50 {
    char unknown_000[0xfec];
    int unknown_fec;
    int unknown_ff0;
    int unknown_ff4;

    unsigned int func_0007FCC0();
};

// Counts which of the three words at +0xfec, +0xff0 and +0xff4 are set.
unsigned int Object_000A1C50::func_0007FCC0()
{
    unsigned int count = 0;
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
