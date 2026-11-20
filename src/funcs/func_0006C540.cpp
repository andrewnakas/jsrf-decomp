extern "C" void *memcpy(void *to, const void *from, unsigned int size);
extern "C" void *memset(void *to, int value, unsigned int size);
void *__cdecl operator new(unsigned int size);

// A part of a description (0x48 bytes).
struct Part_0006CC20 {
    char unknown_00[0x48];
};

// What an entry is made from (0x170 bytes): its parts and their count at +0x168 / +0x16c.
struct Desc_0006C540 {
    char unknown_000[0x168];
    Part_0006CC20 *parts;
    unsigned int count;
};

// An entry of the list at +4 (0x190 bytes).
struct Entry_0006C610 {
    Part_0006CC20 *parts;
    unsigned int count;
    Desc_0006C540 desc;
    int key;
    int unknown_17c;
    char unknown_180[4];
    int unknown_184;
    Entry_0006C610 **link;
    Entry_0006C610 *next;
};

// Object 0x20C750.
struct Object_000149B0 {
    int counter;
    Entry_0006C610 *entries;
    Entry_0006C610 **tail;

    int func_0006C540(Desc_0006C540 *desc, int first, int second);
};

// Appends a new entry (cleared) with a copy of the description and of its parts, the two values at +0x17c / +0x184
// and the next key (+0, counted up); returns the key.
int Object_000149B0::func_0006C540(Desc_0006C540 *desc, int first, int second)
{
    Entry_0006C610 *entry = (Entry_0006C610 *)operator new(sizeof(Entry_0006C610));
    memset(entry, 0, sizeof(Entry_0006C610));
    entry->desc = *desc;
    entry->parts = (Part_0006CC20 *)operator new(desc->count * sizeof(Part_0006CC20));
    entry->count = desc->count;
    memcpy(entry->parts, desc->parts, desc->count * sizeof(Part_0006CC20));
    entry->unknown_17c = first;
    entry->unknown_184 = second;
    *tail = entry;
    entry->link = tail;
    tail = &entry->next;
    entry->next = 0;
    entry->key = counter++;
    return entry->key;
}
