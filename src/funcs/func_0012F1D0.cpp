struct Object_00120420 {
    char unknown_000[0x90e];
    unsigned char cells[0x118];
    unsigned char values[0x118];

    int func_0012DC50(int first, int second, int index);
    int func_0012DE40(int mode);
    int func_0012F1D0(int mode);
};

// Mode 8 only: calls func_0012DE40(8), then clears each of the 280 cells, sets its value to 0xff and calls
// func_0012DC50(0x55, 1, i); returns 1, or 0 for another mode.
int Object_00120420::func_0012F1D0(int mode)
{
    if (mode != 8) {
        return 0;
    }
    func_0012DE40(8);
    for (int i = 0; i < 0x118; i++) {
        cells[i] = 0;
        values[i] = 0xff;
        func_0012DC50(0x55, 1, i);
    }
    return 1;
}
