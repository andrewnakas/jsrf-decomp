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
    void func_000150B0(Table_00015090 *table, int index);
};

// Clears the field at +0x0 of a table's entry, when the slot is not empty.
void Object_00015130::func_000150B0(Table_00015090 *table, int index)
{
    Entry_00015090 *entry = table->entries[index];
    if (entry) {
        entry->unknown_00 = 0;
    }
}
