struct Entry_00015090 {
    int unknown_00;
    int unknown_04;
    int unknown_08;
    int unknown_0c;
    int unknown_10;
};

struct Table_00015090 {
    int unknown_00;
    Entry_00015090 *entries[1];
};

struct Object_00015130 {
    int func_000150D0(Table_00015090 *table, int index);
};

// The field at +0x4 of a table's entry, or 0 when the slot is empty.
int Object_00015130::func_000150D0(Table_00015090 *table, int index)
{
    Entry_00015090 *entry = table->entries[index];
    if (entry) {
        return entry->unknown_04;
    }
    return 0;
}
