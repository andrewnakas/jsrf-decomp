struct Entry_0006DB80 {
    char unknown_00[0x34];
    int unknown_34;
    char unknown_38[0x10];
    int unknown_48;
    char unknown_4c[8];
    Entry_0006DB80 *next;
};

struct Object_0006DB80 {
    char unknown_000[0x804];
    Entry_0006DB80 *entries;
    char unknown_808[4];
    Entry_0006DB80 *head;
    Entry_0006DB80 **tail;

    void func_0006DBB0();
};

// Empties the list at +0x80c and clears the words at +0x34 and +0x48 of every entry of the list at +0x804.
void Object_0006DB80::func_0006DBB0()
{
    head = 0;
    tail = &head;
    for (Entry_0006DB80 *entry = entries; entry; entry = entry->next) {
        entry->unknown_34 = 0;
        entry->unknown_48 = 0;
    }
}
