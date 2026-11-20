struct Entry_00077B70 {
    int unknown_00;
    int unknown_04;
    int value;
    int unknown_0c;
};

struct Object_00077B70 {
    char unknown_000[0xa0];
    Entry_00077B70 *entries;

    int func_00077B70(int index);
};

// Returns the word at +0x8 of an entry of the table the pointer at +0xa0 points to (0x10 bytes each).
int Object_00077B70::func_00077B70(int index)
{
    return entries[index].value;
}
