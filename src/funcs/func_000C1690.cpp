struct Game {
    char unknown_0000[0x87f0];
    int value_87f0;

    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// An entry of data_00251F78: two lists of groups (at 0x24 and 0x38, counts at 0x34 and 0x48).
struct Entry_0006DB80 {
    char unknown_00[0x24];
    int first[4];
    unsigned int firstCount;
    int second[4];
    unsigned int secondCount;
};

struct Object_0006DB80 {
    Entry_0006DB80 *func_0006DB80(int key);
};

extern Object_0006DB80 data_00251F78;

void func_00106FF0(unsigned int id, int key, int which);

// The object in data_00257CE8 (its callers load `ecx` from there; this function does not read it).
struct Object_00157F10 {
    void func_000C1690(int key);
};

// For a set key: when the group at 0x87f0 of data_0022FCE0 is in the entry's first list, func_00106FF0 with 0 and
// then 1; in its second list, with 2 and then 0; in neither, with 3.
void Object_00157F10::func_000C1690(int key)
{
    if (key != -1) {
        int group = data_0022FCE0->value_87f0;
        Entry_0006DB80 *entry = data_00251F78.func_0006DB80(key);
        unsigned int i;
        for (i = 0; i < entry->firstCount; i++) {
            if (group == entry->first[i]) {
                func_00106FF0(group, key, 0);
                func_00106FF0(group, key, 1);
                return;
            }
        }
        for (i = 0; i < entry->secondCount; i++) {
            if (group == entry->second[i]) {
                func_00106FF0(group, key, 2);
                func_00106FF0(group, key, 0);
                return;
            }
        }
        func_00106FF0(group, key, 3);
    }
}
