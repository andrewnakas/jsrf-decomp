// A 32-byte record of the lists at +0xa4: a key first, a value at +0x8.
struct Record_00077BF0 {
    int key;
    char unknown_04[4];
    int value;
    char unknown_0c[0x14];
};

// The counts of the lists (0x10 bytes each, the pointer at +0xa0).
struct Count_00077BF0 {
    int unknown_00;
    int count;
    char unknown_08[8];
};

struct Object_00077BF0 {
    char unknown_00[0xa0];
    Count_00077BF0 *counts;
    Record_00077BF0 *lists[2];

    int func_00077B90(int list, int key);
};

// The value of a record: in list 0 the one whose key is `key` (0 when there is none), in list 1 the record at index
// `key`; 0 for any other list.
int Object_00077BF0::func_00077B90(int list, int key)
{
    switch (list) {
    case 0:
        for (int i = 0; i < counts->count; i++) {
            if (lists[0][i].key == key) {
                return lists[0][i].value;
            }
        }
        break;
    case 1:
        return lists[1][key].value;
    }
    return 0;
}
