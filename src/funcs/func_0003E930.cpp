struct Entry_0003E930 {
    char unknown_000[0xa4];
    int values[2];
    char unknown_0ac[0xc];
    unsigned int stage;
    unsigned int index;
    char unknown_0c0[0x4c];
    Entry_0003E930 *next;
};

struct Object_00039BE0 {
    void func_0003A3A0(unsigned int id, unsigned int entry, int field, int value);
};

extern Object_00039BE0 data_001EFFB0;

struct Object_0003E750 {
    char unknown_000[0x808];
    Entry_0003E930 *entries;

    void func_0003E930();
};

// Hands the two values of every entry of the list at +0x808 that has a stage and an index to the object at
// 0x1EFFB0 (func_0003A3A0).
void Object_0003E750::func_0003E930()
{
    for (Entry_0003E930 *entry = entries; entry; entry = entry->next) {
        if (entry->stage != -1 && entry->index != -1) {
            data_001EFFB0.func_0003A3A0(entry->stage, entry->index, 0, entry->values[0]);
            data_001EFFB0.func_0003A3A0(entry->stage, entry->index, 1, entry->values[1]);
        }
    }
}
