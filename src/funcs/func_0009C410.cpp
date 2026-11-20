struct Game {
    char unknown_0000[0x87f0];
    int value_87f0;

    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// An entry of data_00251F78: a flag at 0x14 and two lists of groups (at 0x24 and 0x38, counts at 0x34 and 0x48).
struct Entry_0006DB80 {
    char unknown_00[0x14];
    int used;
    char unknown_18[0xc];
    int first[4];
    unsigned int firstCount;
    int second[4];
    unsigned int secondCount;

    __forceinline int hasFirst(int group)
    {
        if (used) {
            for (unsigned int i = 0; i < firstCount; i++) {
                if (group == first[i]) {
                    return 1;
                }
            }
        }
        return 0;
    }
    __forceinline int hasSecond(int group)
    {
        if (used) {
            for (unsigned int i = 0; i < secondCount; i++) {
                if (group == second[i]) {
                    return 1;
                }
            }
        }
        return 0;
    }
};

struct Object_0006DB80 {
    Entry_0006DB80 *func_0006DB80(int key);
};

extern Object_0006DB80 data_00251F78;

void func_00106FF0(unsigned int id, int key, int which);

struct Object_0009C3C0 {
    void func_0009C410(int key);
};

// For a set key whose entry is in use: when the group at 0x87f0 of data_0022FCE0 is in the entry's first list,
// func_00106FF0 with 0 and then 1; in its second list, with 2 and then 0; otherwise with 2 and then 3.
void Object_0009C3C0::func_0009C410(int key)
{
    if (key != -1) {
        int group = data_0022FCE0->value_87f0;
        Entry_0006DB80 *entry = data_00251F78.func_0006DB80(key);
        if (entry->hasFirst(group)) {
            func_00106FF0(group, key, 0);
            func_00106FF0(group, key, 1);
        } else if (entry->hasSecond(group)) {
            func_00106FF0(group, key, 2);
            func_00106FF0(group, key, 0);
        } else {
            func_00106FF0(group, key, 2);
            func_00106FF0(group, key, 3);
        }
    }
}
