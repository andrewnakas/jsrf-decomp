struct Game {
    void *func_000128C0(int id);
};

struct Table_000FE650 {
    char unknown_000[0x184];
    int entries[1][16]; // rows of 16; the row count is not known here
};

extern Game *data_0022FCE0;

// Entry [row][column] of the 16-column table at 0x184 of object 0x1165, or 0 when it does not exist.
int func_000FE650(int row, int column)
{
    int result = 0;
    Table_000FE650 *table = (Table_000FE650 *)data_0022FCE0->func_000128C0(0x1165);
    if (table) {
        result = table->entries[row][column];
    }
    return result;
}
