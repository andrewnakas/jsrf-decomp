struct Object_00120420 {
    char unknown_000[0x1e4];
    int state;
    char unknown_1e8[0x958];
    int row;
    int mode;
    int value_b48;
    int value_b4c;

    void func_00132F60();
};

// Clears the row and the word at +0xb4c; the word at +0xb48 becomes 0, or -1 in mode 5 unless the state is 8.
void Object_00120420::func_00132F60()
{
    if (mode == 5) {
        value_b48 = (state == 8) - 1;
        value_b4c = 0;
        row = 0;
    } else {
        value_b48 = 0;
        value_b4c = 0;
        row = 0;
    }
}
