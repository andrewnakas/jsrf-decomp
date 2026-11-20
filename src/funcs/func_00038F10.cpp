void *operator new(unsigned int size);

struct Header_0006EA40;

void __stdcall func_0006EA40(Header_0006EA40 *header);

// One entry of a loaded table: where its data is, where the next entry is, and the data's size (offsets from the
// table's start).
struct Entry_00038F10 {
    unsigned int data;
    unsigned int next;
    unsigned int size;
};

// A table as loaded: how many entries, then the first entry at +0x10.
struct Table_00038F10 {
    int unknown_00;
    unsigned int count;
    char unknown_08[8];
    Entry_00038F10 first;
};

struct File_0002EC50 {
    int unknown_00;
    unsigned int count;
    char unknown_08[8];
    Entry_00038F10 first;
};

// Object 7.
struct Object_000265A0 {
    char unknown_0000[0x1754];
    char **items;
    unsigned int itemCount;
    char unknown_175c[8];
    Header_0006EA40 **motions;
    unsigned int motionCount;

    void func_00038F10(File_0002EC50 *file);
};

// Takes the first two tables of the loaded file: the data of each entry of table 0 into the list at +0x1754 (count
// at +0x1758), and of table 1 into the list at +0x1764 (count at +0x1768), each set up by func_0006EA40; an empty
// entry gives 0, an empty table no list.
void Object_000265A0::func_00038F10(File_0002EC50 *file)
{
    Entry_00038F10 *entry = &file->first;
    for (unsigned int i = 0; i < file->count; i++) {
        Entry_00038F10 *item = (Entry_00038F10 *)((char *)file + entry->data);
        Table_00038F10 *table = (Table_00038F10 *)item;
        item = (Entry_00038F10 *)((char *)item + 0x10);
        entry = (Entry_00038F10 *)((char *)file + entry->next);
        unsigned int j;
        switch (i) {
        case 0:
            itemCount = table->count;
            if (itemCount > 0) {
                items = (char **)operator new(itemCount * 4);
                for (j = 0; j < itemCount; j++) {
                    if (item->size > 0)
                        items[j] = (char *)table + item->data;
                    else
                        items[j] = 0;
                    item = (Entry_00038F10 *)((char *)table + item->next);
                }
            } else {
                items = 0;
            }
            break;
        case 1:
            motionCount = table->count;
            if (motionCount > 0) {
                motions = (Header_0006EA40 **)operator new(motionCount * 4);
                for (j = 0; j < motionCount; j++) {
                    if (item->size > 0) {
                        motions[j] = (Header_0006EA40 *)((char *)table + item->data);
                        func_0006EA40(motions[j]);
                    } else {
                        motions[j] = 0;
                    }
                    item = (Entry_00038F10 *)((char *)table + item->next);
                }
            } else {
                motions = 0;
            }
            break;
        }
    }
}
