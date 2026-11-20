void *func_00025700(unsigned int index, int first, int second, int third);

// The block +0xdc points at: its key (+0x0) and one value per entry (+0x60).
struct State_0001F820 {
    int key;
    char unknown_04[0x5c];
    int *values;
};

// What func_00025700 (9, key) gives: one kind (+0x50) and one index (+0x58) per entry.
struct Data_0001F820 {
    char unknown_00[0x50];
    int *kinds;
    char unknown_54[4];
    int *indices;
};

// What func_00025700 (5) gives: a table of values at +0x18.
struct Table_0001F820 {
    char unknown_00[0x18];
    int *values;
};

// Node child with the table at 0x1C4BA8 (destructor 0x22990).
struct Object_00022990 {
    char unknown_00[0xdc];
    State_0001F820 *state;

    void func_0001F820(int index);
};

// Called by func_00022E50: sets entry `index`'s value in the block at +0xdc: for kind 1 (from func_00025700 (9, key))
// the table value of func_00025700 (5) at the entry's index, when there is that table; otherwise func_00025700 (9,
// key, 2, index).
void Object_00022990::func_0001F820(int index)
{
    Data_0001F820 *data = (Data_0001F820 *)func_00025700(9, state->key, 0, 0);
    switch (data->kinds[index]) {
    case 1: {
        Table_0001F820 *table = (Table_0001F820 *)func_00025700(5, 0, 0, 0);
        if (table)
            state->values[index] = table->values[data->indices[index]];
        break;
    }
    default:
        state->values[index] = (int)func_00025700(9, state->key, 2, index);
        break;
    }
}
