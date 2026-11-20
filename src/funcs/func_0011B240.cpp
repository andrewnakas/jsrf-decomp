struct Entry_0011B240 {
    int id;
    int unknown_04;
    int enabled;
    char unknown_0c[0x14];
};

struct Table_0011B240 {
    Entry_0011B240 entries[24];
};

struct Object_00039BE0 {
    int func_00039D10(unsigned int index);
};

struct Object_0011B240 {
    char unknown_00[0xe4];
    Table_0011B240 table;

    void func_0011B240();
};

extern Table_0011B240 data_00225110;
extern unsigned int data_0021C450[];
extern Object_00039BE0 data_001EFFB0;

// Copies the table of 24 entries from data_00225110 and enables each entry whose flag (data_0021C450 by its id)
// func_00039D10 of data_001EFFB0 reports set.
void Object_0011B240::func_0011B240()
{
    table = data_00225110;
    for (int i = 0; i < 24; i++) {
        if (data_001EFFB0.func_00039D10(data_0021C450[table.entries[i].id])) {
            table.entries[i].enabled = 1;
        }
    }
}
