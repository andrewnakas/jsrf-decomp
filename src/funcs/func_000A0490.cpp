// The two-column table at data_002150E0 and the six-entry cycle at data_00215128.
extern int data_002150E0[][2];
extern int data_00215128[];

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x58];
    int *columns;
    char unknown_05c[0xab4];
    int column;
    unsigned int step;
    char unknown_b18[0x354];
    int index;

    int func_000A0490();
};

// For the moves 0x48 and 0x4c: the step at 0xb14 is the entry of the list at 0x58 that the column at 0xb10
// names, and the result is that row of data_002150E0 at the column. Otherwise the step cycles through 0 to 5 and the
// result is its entry of data_00215128.
int Object_000A1C50::func_000A0490()
{
    if (index == 0x48 || index == 0x4c) {
        step = columns[column];
        return data_002150E0[step][column];
    }
    if (++step >= 6) {
        step = 0;
    }
    return data_00215128[step];
}
