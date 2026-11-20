struct Entry_00067380 {
    int unknown_00;
    int unknown_04;
    int value;
    int unknown_0c;
};

struct Object_00067380 {
    char unknown_000[0x33c];
    Entry_00067380 *entries;

    int func_00067380(int index);
};

// Returns the word at +0x8 of an entry of the table the pointer at +0x33c points to (0x10 bytes each).
int Object_00067380::func_00067380(int index)
{
    return entries[index].value;
}
