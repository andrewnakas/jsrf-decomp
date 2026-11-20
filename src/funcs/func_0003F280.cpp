// The list class at 0x1EFFB0.
struct Object_00039BE0 {
    void func_0003A3A0(unsigned int first, unsigned int second, int index, int value);
};

extern Object_00039BE0 data_001EFFB0;

// An entry of the table at 0x2314B0: its key, two slots of 0x1EFFB0 with their values, and its links in three lists
// (each a pointer to the pointer that points at it and the next entry).
struct Entry_0003E720 {
    char unknown_00[0x9c];
    int key;
    char unknown_a0[4];
    int first;
    int second;
    char unknown_ac[0xc];
    unsigned int slotA;
    unsigned int slotB;
    char unknown_c0[0x40];
    Entry_0003E720 **link;
    Entry_0003E720 *next;
    Entry_0003E720 **link2;
    Entry_0003E720 *next2;
    Entry_0003E720 **link3;
    Entry_0003E720 *next3;
};

// The table at 0x2314B0: entries hashed by the low byte of their key (heads at +0x8, tails at +0x408) and two more
// lists (tails at +0x80c and +0x814).
struct Object_0003E750 {
    void *vtable;
    int unknown_04;
    Entry_0003E720 *buckets[0x100];
    Entry_0003E720 **tails[0x100];
    Entry_0003E720 *head2;
    Entry_0003E720 **tail2;
    Entry_0003E720 *head3;
    Entry_0003E720 **tail3;

    void func_0003F280(int key);
};

// Takes out the entry with this key: clears its two slots of 0x1EFFB0 (func_0003A3A0) when it has them, unlinks it
// from its three lists and frees it.
void Object_0003E750::func_0003F280(int key)
{
    int index = key & 0xff;
    for (Entry_0003E720 *entry = buckets[index]; entry; entry = entry->next) {
        if (entry->key == key) {
            if (entry->slotA != -1 && entry->slotB != -1) {
                data_001EFFB0.func_0003A3A0(entry->slotA, entry->slotB, 0, entry->first);
                data_001EFFB0.func_0003A3A0(entry->slotA, entry->slotB, 1, entry->second);
            }
            if (entry->link) {
                *entry->link = entry->next;
                if (entry->next) {
                    entry->next->link = entry->link;
                } else {
                    tails[index] = entry->link;
                }
            }
            if (entry->link2) {
                *entry->link2 = entry->next2;
                if (entry->next2) {
                    entry->next2->link2 = entry->link2;
                } else {
                    tail2 = entry->link2;
                }
            }
            if (entry->link3) {
                *entry->link3 = entry->next3;
                if (entry->next3) {
                    entry->next3->link3 = entry->link3;
                } else {
                    tail3 = entry->link3;
                }
            }
            delete entry;
            return;
        }
    }
}
