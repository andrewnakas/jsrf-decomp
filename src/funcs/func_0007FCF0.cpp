struct Table_002158B0 {
    int unknown_00;
};

extern Table_002158B0 data_002158B0;

struct Object_0007FCF0 {
    char unknown_000[0x2a4];
    Table_002158B0 *ownTable;
    char unknown_2a8[0x9e8];
    Table_002158B0 *table;

    void func_0007FCF0(int shared);
};

// Points the table at +0xc90 at the shared one at 0x2158B0, or back at its own (+0x2a4).
void Object_0007FCF0::func_0007FCF0(int shared)
{
    if (shared) {
        table = &data_002158B0;
    } else {
        table = ownTable;
    }
}
