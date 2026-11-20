struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Entry_0003BEC0 {
    char unknown_00[0xc];
    int key;
    char unknown_10[0x4c];
};

struct Table_0003BEC0 {
    char unknown_00[0x44];
    unsigned int used;
    unsigned int count;
    int unknown_4c;
    Entry_0003BEC0 *entries;
};

// The count (+0x48) of object 0x19b5 less its word at +0x44, or -1 when the object does not exist.
int func_0003BFE0()
{
    Table_0003BEC0 *table = (Table_0003BEC0 *)data_0022FCE0->func_000128C0(0x19b5);
    if (table) {
        return table->count - table->used;
    }
    return -1;
}
