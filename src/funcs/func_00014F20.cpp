struct Entry_00014ED0 {
    int value;
    void *data[0x20];
    Entry_00014ED0 **link;
    Entry_00014ED0 *next;
};

struct Object_00015130 {
    char unknown_00[8];
    Entry_00014ED0 **tail;

    void func_00014F20(Entry_00014ED0 *entry);
};

// Takes an entry of func_00014ED0 out of the list whose tail link is at +8, frees the blocks it holds and the entry.
void Object_00015130::func_00014F20(Entry_00014ED0 *entry)
{
    *entry->link = entry->next;
    if (entry->next)
        entry->next->link = entry->link;
    else
        tail = entry->link;
    for (unsigned int i = 0; i < 0x20; i++) {
        if (entry->data[i])
            delete entry->data[i];
    }
    delete entry;
}
