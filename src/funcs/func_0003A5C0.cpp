// The object at 0x1EFFB0: 1024 flags in the 32 words at +0x2a1c.
struct Object_00039BE0 {
    char unknown_0000[0x2a1c];
    unsigned int flags[32];

    int func_0003A5C0();
};

// Called by func_00056990: the number of flags set among the 1024 at +0x2a1c.
int Object_00039BE0::func_0003A5C0()
{
    int count = 0;
    for (unsigned int i = 0; i < 32; i++) {
        for (unsigned int j = 0; j < 32; j++) {
            if (flags[i] & (1 << j))
                count++;
        }
    }
    return count;
}
