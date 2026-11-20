struct Record_000673A0 {
    int unknown_00;
    int unknown_04;
    int value;
    char unknown_0c[0x14];
};

struct Object_00067380 {
    char unknown_000[0x340];
    Record_000673A0 *lists[1];

    int func_000673A0(int list, int index);
};

// Returns the word at +0x8 of record `index` of list `list` (pointers from +0x340, 0x20-byte records); 0 when the
// list is missing.
int Object_00067380::func_000673A0(int list, int index)
{
    Record_000673A0 *records = lists[list];
    if (records) {
        return records[index].value;
    }
    return 0;
}
