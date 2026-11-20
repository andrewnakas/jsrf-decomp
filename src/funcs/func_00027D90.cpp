struct Entry_00027D90 {
    char unknown_00[0x2c];
    int used;
};

struct Object_000265A0 {
    char unknown_0000[0x278];
    Entry_00027D90 entries[1];

    void *func_00027D90(int index, int unused1, int unused2);
};

// Handler in the table at 0x1EC200 (called with three arguments at 0x25732): the entry of the table at +0x278 (0x30 bytes each) while its last word is set.
void *Object_000265A0::func_00027D90(int index, int, int)
{
    if (entries[index].used) {
        return &entries[index];
    }
    return 0;
}
