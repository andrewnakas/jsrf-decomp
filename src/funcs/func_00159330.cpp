// VirtualProtect (address, size, protection, old protection).
long __stdcall func_00145A99(void *first, unsigned long second, unsigned long third, unsigned long *result);

// A record the caller gives: four groups of five words (0x50 bytes).
struct Record {
    unsigned long words[20];
};

// A record in the object's memory: four groups of six words (0x60 bytes); the copy leaves each group's last word
// alone.
struct Entry {
    unsigned long words[24];
};

// A class whose table is at 0x1E1610 (11 slots; Release 0x159420, created by 0x159450).
struct Object_001E1610 {
    virtual long __stdcall func_00159330(const Record *records, unsigned int count);  // slot 8

    void *voice;
    unsigned long value_08;
    Entry *entries;
    unsigned int capacity;
};

// Slot 8: makes the entries writable, copies count records into them (groups 2 and 3 swap places) and makes them
// read-only again.
long __stdcall Object_001E1610::func_00159330(const Record *records, unsigned int count)
{
    unsigned long old = 0;
    func_00145A99(entries, capacity * sizeof(Entry), 4, &old);
    Entry *entry = entries;
    for (unsigned int i = 0; i < count; i++) {
        entry->words[0] = records[i].words[0];
        entry->words[1] = records[i].words[1];
        entry->words[2] = records[i].words[2];
        entry->words[3] = records[i].words[3];
        entry->words[4] = records[i].words[4];
        entry->words[6] = records[i].words[5];
        entry->words[7] = records[i].words[6];
        entry->words[8] = records[i].words[7];
        entry->words[9] = records[i].words[8];
        entry->words[10] = records[i].words[9];
        entry->words[12] = records[i].words[15];
        entry->words[13] = records[i].words[16];
        entry->words[14] = records[i].words[17];
        entry->words[15] = records[i].words[18];
        entry->words[16] = records[i].words[19];
        entry->words[18] = records[i].words[10];
        entry->words[19] = records[i].words[11];
        entry->words[20] = records[i].words[12];
        entry->words[21] = records[i].words[13];
        entry->words[22] = records[i].words[14];
        entry++;
    }
    unsigned long previous = 0;
    func_00145A99(entries, capacity * sizeof(Entry), 2, &previous);
    return 0;
}
