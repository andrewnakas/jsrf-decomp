struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Table_0003BEC0 {
    int func_0003BD80(int first, int second, int index);
};

// Passes three values to func_0003BD80 of object 0x19b5; 0 when the object does not exist.
int func_0003BE90(int first, int second, int index)
{
    Table_0003BEC0 *table = (Table_0003BEC0 *)data_0022FCE0->func_000128C0(0x19b5);
    if (table) {
        return table->func_0003BD80(first, second, index);
    }
    return 0;
}
