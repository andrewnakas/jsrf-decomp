struct Entry_00074E50 {
    int unknown_00;
    int unknown_04;
    int value;
    int unknown_0c;
};

struct Object_00074E50 {
    char unknown_000[0xb4];
    Entry_00074E50 *lists[1];

    int func_00074EA0(int list, int index);
};

// The word at +0xc of an entry (0x10 bytes each) of one of the lists at +0xb4, or -1 when that list is missing.
int Object_00074E50::func_00074EA0(int list, int index)
{
    Entry_00074E50 *entries = lists[list];
    if (entries) {
        return entries[index].unknown_0c;
    }
    return -1;
}
