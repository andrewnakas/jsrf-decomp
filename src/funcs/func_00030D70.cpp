void *operator new(unsigned int size);

struct Header_0006EA40;

void __stdcall func_0006EA40(Header_0006EA40 *header);

// A loaded table: its entry count at +0x4, the first entry at +0x10; each entry gives its data's offset and size and
// the offset of the next entry, all from the table's start.
struct Entry_00030D70 {
    unsigned int data;
    unsigned int next;
    unsigned int size;
};

struct Table_00030D70 {
    int unknown_00;
    unsigned int count;
    char unknown_08[0x8];
    Entry_00030D70 first;
};

// A loaded slot (0x30 bytes, from +0x708).
struct Slot_00030D70 {
    char unknown_00[0x8];
    void **items;
    unsigned int itemCount;
    char unknown_10[0x8];
    void **first;
    unsigned int firstCount;
    void **second;
    unsigned int secondCount;
    char unknown_28[0x8];
};

// Object 7.
struct Object_000265A0 {
    char unknown_000[0x708];
    Slot_00030D70 slots[1];
    int current;

    void func_00030D70(void *data);
};

// Called by func_00031160: points the lists of the current slot at the entries of the loaded table's three
// sub-tables (0 for an empty entry): the first into +0x8 / +0xc, the second (each run through func_0006EA40) into
// +0x18 / +0x1c, the third (likewise) into +0x20 / +0x24.
void Object_000265A0::func_00030D70(void *data)
{
    Slot_00030D70 *slot = &slots[current];
    Table_00030D70 *table = (Table_00030D70 *)data;
    Entry_00030D70 *entry = &table->first;
    for (unsigned int i = 0; i < table->count; i++) {
        Entry_00030D70 *item = (Entry_00030D70 *)((char *)table + entry->data);
        Table_00030D70 *sub = (Table_00030D70 *)item;
        item = (Entry_00030D70 *)((char *)item + 0x10);
        entry = (Entry_00030D70 *)((char *)table + entry->next);
        unsigned int j;
        switch (i) {
        case 0:
            slot->itemCount = sub->count;
            if (slot->itemCount > 0) {
                slot->items = (void **)operator new(slot->itemCount * 4);
                for (j = 0; j < slot->itemCount; j++) {
                    if (item->size > 0)
                        slot->items[j] = (char *)sub + item->data;
                    else
                        slot->items[j] = 0;
                    item = (Entry_00030D70 *)((char *)sub + item->next);
                }
            } else {
                slot->items = 0;
            }
            break;
        case 1:
            slot->firstCount = sub->count;
            if (slot->firstCount > 0) {
                slot->first = (void **)operator new(slot->firstCount * 4);
                for (j = 0; j < slot->firstCount; j++) {
                    if (item->size > 0) {
                        slot->first[j] = (char *)sub + item->data;
                        func_0006EA40((Header_0006EA40 *)slot->first[j]);
                    } else {
                        slot->first[j] = 0;
                    }
                    item = (Entry_00030D70 *)((char *)sub + item->next);
                }
            } else {
                slot->first = 0;
            }
            break;
        case 2:
            slot->secondCount = sub->count;
            if (slot->secondCount > 0) {
                slot->second = (void **)operator new(slot->secondCount * 4);
                for (j = 0; j < slot->secondCount; j++) {
                    if (item->size > 0) {
                        slot->second[j] = (char *)sub + item->data;
                        func_0006EA40((Header_0006EA40 *)slot->second[j]);
                    } else {
                        slot->second[j] = 0;
                    }
                    item = (Entry_00030D70 *)((char *)sub + item->next);
                }
            } else {
                slot->second = 0;
            }
            break;
        }
    }
}
