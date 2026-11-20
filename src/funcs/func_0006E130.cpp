struct Entry_0006E130 {
    int id;
    int unknown_04;
    int value;
    int unknown_0c;
    Entry_0006E130 *next;
};

struct Object_0006E130 {
    char unknown_0000[0x14];
    Entry_0006E130 *buckets[0x100];
    char unknown_0414[0xbd0];
    int current0;
    int current1;
    int ids0[10];
    int ids1[10];

    int func_0006E130(int id);
};

// The value of the entry registered under an id (0x100 and 0x101 stand for the current ones of two tables), or -1.
int Object_0006E130::func_0006E130(int id)
{
    switch (id) {
    case 0x100:
        id = ids0[current0];
        break;
    case 0x101:
        id = ids1[current1];
        break;
    }
    for (Entry_0006E130 *entry = buckets[id & 0xff]; entry; entry = entry->next) {
        if (entry->id == id) {
            return entry->value;
        }
    }
    return -1;
}
