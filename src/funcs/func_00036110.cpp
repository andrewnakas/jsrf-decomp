// The table at +0xc48: from +0x1c, where the slots of each part begin.
struct Parts_0006A1B0 {
    char unknown_00[0x1c];
    unsigned int first[3];
};

struct Object_0006A1B0 {
    char unknown_000[0xc48];
    Parts_0006A1B0 *parts;

    int func_0006A1B0(int part);
};

struct Entry_00036050 {
    int key;
    Object_0006A1B0 *object;
    char unknown_08[8];
    Entry_00036050 *next;
};

struct Object_000265A0 {
    char unknown_0000[0x1c4];
    Entry_00036050 *entries;
    char unknown_01c8[4];
    Entry_00036050 *entry;
    int unknown_1d0;
    int key;
    char unknown_01d8[4];
    unsigned int unknown_1dc;
    unsigned int unknown_1e0;

    int func_00036110(int key);
};

// Handler 4 of the table at 0x1EC068: for the entry with `key` in the list at +0x1c4 whose object's func_0006A1B0 (1)
// gives 0, clears +0x1d0, keeps the key at +0x1d4, the entry at +0x1cc and the starts of parts 1 and 2 at +0x1dc and
// +0x1e0, and returns 1; otherwise 0.
int Object_000265A0::func_00036110(int key)
{
    for (Entry_00036050 *item = entries; item; item = item->next) {
        if (item->key == key) {
            if (item->object->func_0006A1B0(1))
                return 0;
            unknown_1d0 = 0;
            this->key = key;
            unknown_1dc = item->object->parts->first[1];
            unknown_1e0 = item->object->parts->first[2];
            entry = item;
            return 1;
        }
    }
    return 0;
}
