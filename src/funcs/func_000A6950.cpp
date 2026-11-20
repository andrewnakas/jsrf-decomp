struct Table_00065F10;

struct Object_00039A10 {
    int func_00065F10(Table_00065F10 *table, int *indices, unsigned int count);
};

extern Object_00039A10 data_001FB820;

struct Object_000A63C0 {
    char unknown_000[0x78];
    Table_00065F10 *table;

    int func_000A6950(int *indices, unsigned int count);
};

// Whether a section may be used: always with no table at +0x78; otherwise when func_00065F10 of 0x1FB820 returns 0
// for the table and the section's indices.
int Object_000A63C0::func_000A6950(int *indices, unsigned int count)
{
    if (table) {
        return data_001FB820.func_00065F10(table, indices, count) == 0;
    }
    return 1;
}
