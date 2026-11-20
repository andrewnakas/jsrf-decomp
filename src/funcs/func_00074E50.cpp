struct Entry_00074E50 {
    int unknown_00;
    int unknown_04;
    int value;
    int unknown_0c;
};

struct Object_00074E50 {
    char unknown_000[0xb0];
    Entry_00074E50 *entries;

    int func_00074E50(int index);
};

// Returns the word at +0x8 of an entry of the table the pointer at +0xb0 points to (0x10 bytes each).
int Object_00074E50::func_00074E50(int index)
{
    return entries[index].value;
}
