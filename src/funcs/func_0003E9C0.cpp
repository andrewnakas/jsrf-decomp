struct Vector3 {
    float x;
    float y;
    float z;
};

// A convex cell (0x90 bytes): six points on its faces, then the six face normals.
struct Cell_000A6DC0 {
    Vector3 points[6];
    Vector3 normals[6];
};

int func_0004A6F0(Vector3 *point, Cell_000A6DC0 *cell);

// An entry of the list at +0x808: its own cell (+0x4, used while +0xa0 is set), a value (+0x9c), a key (+0xe8) and,
// with +0xe4, a second cell it points at (+0xf8).
struct Entry_0003E830 {
    int unknown_000;
    Cell_000A6DC0 cell;
    char unknown_094[8];
    int value;
    int unknown_0a0;
    char unknown_0a4[0x40];
    int unknown_0e4;
    int key;
    char unknown_0ec[0xc];
    Cell_000A6DC0 *other;
    char unknown_0fc[0x10];
    Entry_0003E830 *next;
};

// An entry of the list at +0x818: a point, the value it took, whether a second cell held it, its key and the next.
struct Item_0003E9A0 {
    Vector3 point;
    int value;
    int found;
    int key;
    Item_0003E9A0 *next;
};

// The object at 0x2314B0.
struct Object_0003E750 {
    char unknown_000[0x808];
    Entry_0003E830 *entries;
    char unknown_80c[0xc];
    Item_0003E9A0 *head;

    void func_0003E9C0();
};

// For each item of the list at +0x818, looks through the entries of the list at +0x808 with another key: one whose
// second cell (+0xe4 set, +0xa0 clear) holds the item's point marks it found (+0x10) and gives it its value; the
// first whose own cell (+0xa0 set) holds it gives it its value and ends the search.
void Object_0003E750::func_0003E9C0()
{
    for (Item_0003E9A0 *item = head; item; item = item->next) {
        for (Entry_0003E830 *entry = entries; entry; entry = entry->next) {
            if (entry->key == item->key)
                continue;
            if (entry->unknown_0e4 && !entry->unknown_0a0 && entry->other &&
                func_0004A6F0(&item->point, entry->other)) {
                item->found = 1;
                item->value = entry->value;
            }
            if (entry->unknown_0a0 && func_0004A6F0(&item->point, &entry->cell)) {
                item->value = entry->value;
                break;
            }
        }
    }
}
