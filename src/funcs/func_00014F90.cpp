struct Entry_00014F90 {
    int value;
    int unknown_04;
    int unknown_08;
    int unknown_0c;
    int unknown_10;
    int unknown_14;
    Entry_00014F90 **link;
    Entry_00014F90 *next;
};

struct Object_00015130 {
    char unknown_00[0x10];
    Entry_00014F90 **tail;

    Entry_00014F90 *func_00014F90(int value);
};

// Appends a new 32-byte entry holding a value to the list (tail link at +0x10) and returns it.
Entry_00014F90 *Object_00015130::func_00014F90(int value)
{
    Entry_00014F90 *entry = new Entry_00014F90;
    entry->value = value;
    entry->unknown_04 = 0;
    entry->unknown_08 = 0;
    entry->unknown_0c = 0;
    entry->unknown_10 = 0;
    entry->unknown_14 = 0;
    entry->next = 0;
    *tail = entry;
    entry->link = tail;
    tail = &entry->next;
    return entry;
}
