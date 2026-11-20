// An entry of the list at +0x1584: a key first, the next entry at +0xd0.
struct Entry_00038B50 {
    int key;
    char unknown_04[0xcc];
    Entry_00038B50 *next;
};

struct Object_000265A0 {
    char unknown_0000[0x1584];
    Entry_00038B50 *entries;

    void *func_00038B50(int key, int skip, int unused);
};

// Handler 8 of the table at 0x1EC200: the entry of the list at +0x1584 with a key (0 without one); 0 when the second
// argument is set.
void *Object_000265A0::func_00038B50(int key, int skip, int)
{
    Entry_00038B50 **link = &entries;
    while (*link && (*link)->key != key) {
        link = &(*link)->next;
    }
    if (skip) {
        return 0;
    }
    return *link;
}
