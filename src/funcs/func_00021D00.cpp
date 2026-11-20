void func_00116950(int index);
void func_00117280(int slot, int track);

// A list in the block at +0xdc: its count, keys and values.
struct List_00021D00 {
    unsigned int count;
    unsigned int *keys;
    int *values;
};

struct State_00021D00 {
    char unknown_000[4];
    unsigned int limit;
    char unknown_008[0x194];
    List_00021D00 list;
};

// Node child with the table at 0x1C4BA8 (destructor 0x22990).
struct Object_00022990 {
    char unknown_00[0x94];
    unsigned int key;
    char unknown_98[0x20];
    int slot;
    char unknown_bc[0x20];
    State_00021D00 *state;

    void func_00021D00();
};

// Called by func_00023790: when +0x94 is one of the keys of the list at +0x19c of the block at +0xdc, runs
// func_00116950 for the slot at +0xb8, switches the slot (0 <-> 1) and, unless that key is the last one or the next
// key is not below the block's word at +0x4, func_00117280 with the new slot and the next key's value.
void Object_00022990::func_00021D00()
{
    List_00021D00 *list = &state->list;
    for (unsigned int i = 0; i < list->count; i++) {
        if (key == list->keys[i]) {
            func_00116950(slot);
            slot ^= 1;
            if (i < list->count - 1 && list->keys[i + 1] < state->limit)
                func_00117280(slot, list->values[i + 1]);
            return;
        }
    }
}
