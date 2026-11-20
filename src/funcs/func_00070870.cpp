struct Entry_00070870 {
    char unknown_00[0x24];
    int value;
};

struct Object_00070850 {
    char unknown_00[0xe8];
    Entry_00070870 entries[1];

    int func_00070870(int index);
};

// Returns the word at +0x24 of an entry of the table at +0xe8 (0x28 bytes each).
int Object_00070850::func_00070870(int index)
{
    return entries[index].value;
}
