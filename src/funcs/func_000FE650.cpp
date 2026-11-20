struct Game {
    void *func_000128C0(int id);
};

// Object 0x1165 (its constructor func_000FE740 clears five rows of the table).
struct Object_000FDF30 {
    char unknown_000[0x184];
    int table[5][16];
};

extern Game *data_0022FCE0;

// Entry [row][column] of the 16-column table at 0x184 of object 0x1165, or 0 when it does not exist.
int func_000FE650(int row, int column)
{
    int result = 0;
    Object_000FDF30 *object = (Object_000FDF30 *)data_0022FCE0->func_000128C0(0x1165);
    if (object) {
        result = object->table[row][column];
    }
    return result;
}
