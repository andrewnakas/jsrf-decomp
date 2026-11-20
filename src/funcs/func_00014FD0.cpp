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

    void func_00014FD0(Entry_00014F90 *entry);
};

// Unlinks an entry from the list (links at +0x18/+0x1c, tail link at +0x10) of the object at 0x1EB994 and deletes it.
void Object_00015130::func_00014FD0(Entry_00014F90 *entry)
{
    *entry->link = entry->next;
    if (entry->next) {
        entry->next->link = entry->link;
    } else {
        tail = entry->link;
    }
    delete entry;
}
