struct Entry_38860 {
    int id;
    char unknown_04[0xc - 4];
};

extern Entry_38860 data_001EEB68[];

// The index of an id in the table at 0x1EEB68 (ended by -1), or 0 when it is not there.
int func_00038860(int id)
{
    for (int i = 0; data_001EEB68[i].id != -1; i++) {
        if (id == data_001EEB68[i].id) {
            return i;
        }
    }
    return 0;
}
