struct Entry_00014ED0 {
    int value;
    int data[0x20];
    Entry_00014ED0 **link;
    Entry_00014ED0 *next;
};

struct Object_00015130 {
    char unknown_00[8];
    Entry_00014ED0 **tail;

    Entry_00014ED0 *func_00014ED0(int value);
};

// Appends a new 0x8c-byte entry holding a value and 32 cleared words to the list whose tail link is at +8 and
// returns it.
Entry_00014ED0 *Object_00015130::func_00014ED0(int value)
{
    Entry_00014ED0 *entry = new Entry_00014ED0;
    entry->value = value;
    for (int i = 0; i < 0x20; i++)
        entry->data[i] = 0;
    entry->next = 0;
    *tail = entry;
    entry->link = tail;
    tail = &entry->next;
    return entry;
}
