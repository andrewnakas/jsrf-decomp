// The object at 0x20C6C0.
struct Object_0006A960 {
    char unknown_00[8];
    unsigned int bits[1];

    int func_0006AC10(int index);
};

// Says whether bit `index` of the set at +0x8 is set; negative indices give 0.
int Object_0006A960::func_0006AC10(int index)
{
    if (index >= 0 && (bits[index >> 5] & (1 << (index & 0x1f)))) {
        return 1;
    }
    return 0;
}
