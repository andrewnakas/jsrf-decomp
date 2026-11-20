// An entry of the list at +0x280: a kind, a byte at +0x5, the next entry at +0x38.
struct Entry_00089B50 {
    int kind;
    char unknown_04;
    char state;
    char unknown_06[0x32];
    Entry_00089B50 *next;
};

// The player object.
struct Object_000A1C50 {
    char unknown_000[0x280];
    Entry_00089B50 *entries;

    int func_00089B50();
};

// 1 when an entry of kind 1 or 10 of the list at +0x280 is not in state 2, else 0.
int Object_000A1C50::func_00089B50()
{
    for (Entry_00089B50 *entry = entries; entry; entry = entry->next) {
        if ((entry->kind == 1 || entry->kind == 10) && entry->state != 2) {
            return 1;
        }
    }
    return 0;
}
