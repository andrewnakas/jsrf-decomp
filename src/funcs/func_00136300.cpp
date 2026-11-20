// The class whose table is at 0x1DE828.
struct Object_00134880 {
    char unknown_000[0x11c];
    unsigned char first[0x118];
    unsigned char second[0x118];

    int func_00136070(int first, int second, int index);
    int func_00136300(int mode);
};

// Mode 8 only: clears both 280-byte tables and calls func_00136070(0x55, 8, i) for each entry; returns 1, or 0
// for another mode.
int Object_00134880::func_00136300(int mode)
{
    if (mode != 8) {
        return 0;
    }
    for (int i = 0; i < 0x118; i++) {
        first[i] = 0;
        second[i] = 0;
        func_00136070(0x55, 8, i);
    }
    return 1;
}
