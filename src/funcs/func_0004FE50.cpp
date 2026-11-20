// A registration: a kind and its argument (the list at 0x1FA060).
struct Item_0004FE50 {
    int kind;
    int id;
    Item_0004FE50 *next;
};

extern Item_0004FE50 *data_001FA060;

// Whether id is registered with kind 2.
inline int registered_0004FE50(int id)
{
    for (Item_0004FE50 *item = data_001FA060; item; item = item->next) {
        if (item->kind == 2 && item->id == id)
            return 1;
    }
    return 0;
}

// An entry of the table at +0x44 (0x20 bytes): its id.
struct Entry_0004FE50 {
    int id;
    char unknown_04[0x1c];
};

struct Table_0004FE50 {
    Entry_0004FE50 *entries;
};

// Object 0x12ac (destructor 0x4FBC0): ids at +0x88c (with their count) and the slots they stand for at +0x894.
struct Object_0004FC40 {
    char unknown_000[0x44];
    Table_0004FE50 *table;
    char unknown_048[0x844];
    unsigned int *ids;
    unsigned int count;

    int func_0004FE50(unsigned int start);
};

// 1 when the entries of the five ids from `start` on and the four before it (around the ring of ids at +0x88c) are
// all registered with kind 2 (0x1FA060), else 0.
int Object_0004FC40::func_0004FE50(unsigned int start)
{
    unsigned int i;
    for (i = 0; i < 5; i++) {
        int id = table->entries[ids[(i + start) % count]].id;
        if (!registered_0004FE50(id))
            return 0;
    }
    for (i = 1; i < 5; i++) {
        int id = table->entries[ids[(count * 9 - i + start) % count]].id;
        if (!registered_0004FE50(id))
            return 0;
    }
    return 1;
}
