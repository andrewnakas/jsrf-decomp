struct Entry_2ABC0 {
    int id;
    char unknown_04[0x14 - 4];
};

extern Entry_2ABC0 data_001EC690[];

// The index of an id in the table at 0x1EC690 (ended by -1), or 0 when it is not there.
int func_0002ABC0(int id)
{
    for (int i = 0; data_001EC690[i].id != -1; i++) {
        if (id == data_001EC690[i].id) {
            return i;
        }
    }
    return 0;
}
