struct Entry_0006E130 {
    int id;
    int count;
    int value;
    Entry_0006E130 **link;
    Entry_0006E130 *next;
    Entry_0006E130 *nextFree;
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
    virtual void __stdcall slot14();
    virtual void __stdcall slot15(int value);
};

extern Device_00251D6C *data_00251D6C;

struct Object_0006E130 {
    int unknown_0000[2];
    Entry_0006E130 *freeHead;
    Entry_0006E130 *freeTail;
    int releases;
    Entry_0006E130 *buckets[0x100];
    Entry_0006E130 **tails[0x100];
    void *values[0x100];

    void func_0006E7B0(int id);
};

// Releases the entry registered under an id: when its count drops to zero, unlinks it from its chain, appends it to
// the free list (+8/+0xc), clears its value's slot (+0x814) and frees the value (slot 15 of 0x251D6C); counts the release (+0x10).
void Object_0006E130::func_0006E7B0(int id)
{
    int bucket = id & 0xff;
    for (Entry_0006E130 *entry = buckets[bucket]; entry; entry = entry->next) {
        if (entry->id == id) {
            if (--entry->count <= 0) {
                *entry->link = entry->next;
                if (entry->next) {
                    entry->next->link = entry->link;
                } else {
                    tails[bucket] = entry->link;
                }
                if (freeTail) {
                    freeTail->nextFree = entry;
                    entry->nextFree = 0;
                    freeTail = entry;
                } else {
                    freeHead = entry;
                    entry->nextFree = 0;
                    freeTail = freeHead;
                }
                values[entry->value] = 0;
                data_00251D6C->slot15(entry->value);
            }
            releases++;
            return;
        }
    }
}
