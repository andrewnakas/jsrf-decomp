struct Object_00039BE0 {
    char unknown_0000[0x6f58];
    int grid_6f58[2][4][5];
    int grid_6ff8[2][4][5];

    void func_0003A7F0(int row, int column, int value, int page);
    int func_0003A820(int row, int column, int page);
    void func_0003A840(int row, int column, int value, int page);
    int func_0003A870(int row, int column, int page);
};

void Object_00039BE0::func_0003A840(int row, int column, int value, int page)
{
    grid_6ff8[page][row][column] = value;
}
