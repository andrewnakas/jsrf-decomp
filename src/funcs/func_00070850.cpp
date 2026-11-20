struct Entry_00070850 {
    int value;
    char unknown_04[0x24];
};

struct Object_00070850 {
    char unknown_00[0xe8];
    Entry_00070850 entries[1];

    int func_00070850(int index);
};

// Returns the word at +0x0 of an entry of the table at +0xe8 (0x28 bytes each).
int Object_00070850::func_00070850(int index)
{
    return entries[index].value;
}
