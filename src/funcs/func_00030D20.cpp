struct Entry_00030D20 {
    int value;
    char unknown_04[0x2c];
};

struct Object_000265A0 {
    char unknown_0000[0x734];
    Entry_00030D20 entries[1];

    int func_00030D20(int index);
};

// Returns the first word of an entry of the table at +0x734 (0x30 bytes each).
int Object_000265A0::func_00030D20(int index)
{
    return entries[index].value;
}
