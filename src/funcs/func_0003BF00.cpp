struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Entry_0003BEC0 {
    char unknown_00[0xc];
    int key;
    int value;
    char unknown_14[0x48];
};

struct Table_0003BEC0 {
    char unknown_00[0x48];
    unsigned int count;
    int unknown_4c;
    Entry_0003BEC0 *entries;
};

// Counts the entries of object 0x19b5 whose word at +0x10 equals a value (func_0003BEC0 does it for +0xc).
int func_0003BF00(int value)
{
    Table_0003BEC0 *table = (Table_0003BEC0 *)data_0022FCE0->func_000128C0(0x19b5);
    if (table) {
        int found = 0;
        for (unsigned int i = 0; i < table->count; i++) {
            if (table->entries[i].value == value) {
                found++;
            }
        }
        return found;
    }
    return 0;
}
