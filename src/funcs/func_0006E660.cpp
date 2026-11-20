struct Entry_0006E130 {
    unsigned int id;
    int count;
    unsigned int value;
    Entry_0006E130 **link;
    Entry_0006E130 *next;
    Entry_0006E130 *nextFree;
};

// What slot 14 of 0x251D6C makes an entry's value from (16 bytes).
struct Desc_0006E660 {
    void *data;
    int size;
    int flags;
    int unknown_0c;
};

struct Device_00251D6C {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8();
    virtual void __stdcall slot9();
    virtual void __stdcall slot10();
    virtual void __stdcall slot11();
    virtual void __stdcall slot12();
    virtual void __stdcall slot13();
    virtual void __stdcall slot14(unsigned int index, Desc_0006E660 *desc);
};

extern Device_00251D6C *data_00251D6C;

// The fixed ids of the indexed entries.
extern unsigned int data_0020CC40[];

struct Object_0006E130 {
    int unknown_0000[2];
    Entry_0006E130 *freeHead;
    Entry_0006E130 *freeTail;
    int releases;
    Entry_0006E130 *buckets[0x100];
    Entry_0006E130 **tails[0x100];
    int used[500];

    int func_0006E660(int index, void *data);
};

// Fills the entry with the fixed id of `index` (data_0020CC40): when the table does not hold it yet, an entry from the
// free list (+8) with count 1 is appended to its bucket and given the first free value slot of 500 (+0x814). Slot 14
// of 0x251D6C then makes the entry's value from `data` (0x400 bytes, flags 0x1000206). Returns the id.
int Object_0006E130::func_0006E660(int index, void *data)
{
    unsigned int id = data_0020CC40[index];
    unsigned int bucket = id & 0xff;
    Entry_0006E130 *entry;
    for (entry = buckets[bucket]; entry; entry = entry->next) {
        if (entry->id == id) {
            break;
        }
    }
    if (!entry) {
        entry = 0;
        if (freeHead) {
            entry = freeHead;
            freeHead = freeHead->nextFree;
            if (!freeHead) {
                freeTail = 0;
            }
            releases--;
            entry->id = id;
            entry->count = 1;
            *tails[bucket] = entry;
            entry->link = tails[bucket];
            entry->next = 0;
            tails[bucket] = &entry->next;
            unsigned int slot;
            for (slot = 0; slot < 500; slot++) {
                if (!used[slot]) {
                    break;
                }
            }
            if (slot < 500) {
                entry->value = slot;
                used[slot] = 1;
            }
        }
    }
    Desc_0006E660 desc;
    desc.data = data;
    desc.size = 0x400;
    desc.flags = 0x1000206;
    desc.unknown_0c = 0;
    data_00251D6C->slot14(entry->value, &desc);
    return id;
}
