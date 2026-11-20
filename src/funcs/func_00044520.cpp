void __cdecl operator delete(void *memory) throw();

// An entry of the list at 0x1F9138: its id at +0x30, the link that points at it (+0x34) and the next entry (+0x38).
struct Entry_00044520 {
    char unknown_00[0x30];
    int id;
    Entry_00044520 **link;
    Entry_00044520 *next;
};

// The list at 0x1F9138 (func_00043700 gives its head).
struct Object_00043700 {
    Entry_00044520 *head;
    Entry_00044520 **tail;

    void func_00044520(int id);
};

// Called by the destructor 0x448B0: unlinks and frees the first entry with the id.
void Object_00043700::func_00044520(int id)
{
    for (Entry_00044520 *entry = head; entry; entry = entry->next) {
        if (entry->id == id) {
            *entry->link = entry->next;
            if (entry->next) {
                entry->next->link = entry->link;
            } else {
                tail = entry->link;
            }
            operator delete(entry);
            return;
        }
    }
}
