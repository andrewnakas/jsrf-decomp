// An entry of the list at +0x1584: a key first, a word at +0xcc, the next entry at +0xd0.
struct Entry_00038B50 {
    int key;
    char unknown_04[0xc8];
    int unknown_cc;
    Entry_00038B50 *next;
};

struct Object_000265A0 {
    char unknown_0000[0x1584];
    Entry_00038B50 *entries;

    int func_00038B10(int key);
};

// Handler 8 of the table at 0x1EC178: whether the word at +0xcc of the entry with a key is clear (it reads through
// a missing entry as well).
int Object_000265A0::func_00038B10(int key)
{
    Entry_00038B50 **link = &entries;
    while (*link && (*link)->key != key) {
        link = &(*link)->next;
    }
    return (*link)->unknown_cc == 0;
}
