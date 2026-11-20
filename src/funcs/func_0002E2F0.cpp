struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// A loaded table: its entry count at +0x4, the first entry at +0x10; each entry gives its data's offset and size and
// the offset of the next entry, all from the table's start.
struct Entry_0002E2F0 {
    unsigned int data;
    unsigned int next;
    unsigned int size;
};

struct Table_0002E2F0 {
    int unknown_00;
    unsigned int count;
    char unknown_08[0x8];
    Entry_0002E2F0 first;
};

// Object 0x1de2.
struct Scene_00121880 {
    char unknown_0000[0x2a54];
    void *items[0x40];
};

// Object 7.
struct Object_000265A0 {
    void func_0002E2F0(void *data);
};

// Points object 0x1de2's items at +0x2a54 at the entries of the loaded table (0 for an empty one).
void Object_000265A0::func_0002E2F0(void *data)
{
    Scene_00121880 *scene = (Scene_00121880 *)data_0022FCE0->func_000128C0(0x1de2);
    Table_0002E2F0 *table = (Table_0002E2F0 *)data;
    Entry_0002E2F0 *entry = &table->first;
    for (unsigned int i = 0; i < table->count; i++) {
        Entry_0002E2F0 *current = entry;
        entry = (Entry_0002E2F0 *)((char *)table + entry->next);
        if (current->size > 0)
            scene->items[i] = (char *)table + current->data;
        else
            scene->items[i] = 0;
    }
}
