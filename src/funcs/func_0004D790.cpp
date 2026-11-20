struct Object_0004D790 {
    char unknown_000[0x264];
    int unknown_264;
    char unknown_268[0xd8c];
    unsigned int masks[1];

    int func_0004D790(int index, unsigned int bits);
};

// Unless the word at +0x264 is set, says whether one of the bits is set in the mask at +0xff4 an index picks.
int Object_0004D790::func_0004D790(int index, unsigned int bits)
{
    if (!unknown_264 && (masks[index] & bits)) {
        return 1;
    }
    return 0;
}
