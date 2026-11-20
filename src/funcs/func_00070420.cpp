struct Object_00039BE0 {
    int func_00039D10(unsigned int id);
};

extern Object_00039BE0 data_001EFFB0;

// One of the 0x18 entries at +0xe8 (0x28 bytes).
struct Entry_00070420 {
    unsigned int kind;
    unsigned int id;
    int ready;
    char unknown_0c[0x1c];
};

struct Object_00071040 {
    char unknown_000[0xe8];
    Entry_00070420 entries[0x18];

    void func_00070420();
};

// Marks the entries of kinds 0 to 2 and 8 ready; asks func_00039D10 of 0x1EFFB0 about the id of the others.
void Object_00071040::func_00070420()
{
    for (unsigned int i = 0; i < 0x18; i++) {
        Entry_00070420 *entry = &entries[i];
        switch (entry->kind) {
        case 0:
        case 1:
        case 2:
        case 8:
            entry->ready = 1;
            break;
        default:
            entry->ready = data_001EFFB0.func_00039D10(entry->id);
            break;
        }
    }
}
