struct Object_000265A0 {
    char unknown_0000[0x15b0];
    int unknown_15b0;
    char unknown_15b4[0x8];
    int unknown_15bc;
    int unknown_15c0;
    int unknown_15c4;

    int func_0002BFB0(int argument);
};

// Handler 17 of the table at 0x1EC068: with +0x15bc set, clears +0x15c0 and sets +0x15b0 to 6; else clears +0x15b0
// and +0x15c4 and sets +0x15c0.
int Object_000265A0::func_0002BFB0(int argument)
{
    if (unknown_15bc != 0) {
        unknown_15c0 = 0;
        unknown_15b0 = 6;
        return 1;
    }
    unknown_15b0 = 0;
    unknown_15c4 = 0;
    unknown_15c0 = 1;
    return 1;
}
