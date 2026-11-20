// A row of the grid at +0x62C: five ids and five values (0x30 bytes).
struct Row_00135710 {
    int ids[5];
    int unknown_14;
    int values[5];
    int unknown_2c;
};

struct Slot_00135710 {
    int column;
    char unknown_04[0x34];
};

struct Object_00134880 {
    char unknown_000[0x560];
    Slot_00135710 slots[3];
    char unknown_608[0x24];
    Row_00135710 rows[4];

    int func_00135710(int id, int value, int row);
};

// 0 when a cell of another row than `row` holds `id` and `value` (for a negative id, only in that row's slot
// column); 1 otherwise.
int Object_00134880::func_00135710(int id, int value, int row)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (rows[i].ids[j] == id && (id >= 0 || j == slots[row].column) && rows[i].values[j] == value
                && i != row) {
                return 0;
            }
        }
    }
    return 1;
}
