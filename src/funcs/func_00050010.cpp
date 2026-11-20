// A record of the list at +0x44 (0x20 bytes): its id first.
struct Record_00050010 {
    int id;
    char unknown_04[0x1c];
};

struct Records_00050010 {
    Record_00050010 *records;
};

// The list at 0x1FA05C.
struct Object_0004D8C0 {
    void func_0004DAE0(const int *keep, unsigned int count);
};

extern Object_0004D8C0 data_001FA05C;

// Object 0x12ac (destructor 0x4FBC0): ids at +0x88c (with their count) and the slots they stand for at +0x894.
struct Object_0004FC40 {
    char unknown_000[0x44];
    Records_00050010 *list;
    char unknown_048[0x81c];
    int kept[10];
    int *ids;
    unsigned int count;

    void func_00050010(unsigned int index);
};

// Gathers, without repeats, the record ids (list at +0x44) of the five ids from `index` on and of the four before it
// (wrapping around the ids at +0x88c) at +0x864, and has the list at 0x1FA05C keep only those (func_0004DAE0).
void Object_0004FC40::func_00050010(unsigned int index)
{
    unsigned int found = 0;
    unsigned int i;
    for (i = 0; i < 5; i++) {
        int id = list->records[ids[(index + i) % count]].id;
        unsigned int j;
        for (j = 0; j < found; j++) {
            if (kept[j] == id) {
                break;
            }
        }
        if (j >= found) {
            kept[found++] = id;
        }
    }
    for (i = 1; i < 5; i++) {
        int id = list->records[ids[(count * 9 - i + index) % count]].id;
        unsigned int j;
        for (j = 0; j < found; j++) {
            if (kept[j] == id) {
                break;
            }
        }
        if (j >= found) {
            kept[found++] = id;
        }
    }
    data_001FA05C.func_0004DAE0(kept, found);
}
