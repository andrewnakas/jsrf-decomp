// The object at 0x1EFFB0: 256 flags in the eight words at +0x118.
struct Object_00039BE0 {
    char unknown_000[0x118];
    unsigned int flags[8];

    int func_00039FD0();
};

// Called by func_0003CE10, func_00056990 and others: the number of flags set among the 256 at +0x118.
int Object_00039BE0::func_00039FD0()
{
    int count = 0;
    for (unsigned int i = 0; i < 8; i++) {
        for (unsigned int j = 0; j < 32; j++) {
            if (flags[i] & (1 << j))
                count++;
        }
    }
    return count;
}
