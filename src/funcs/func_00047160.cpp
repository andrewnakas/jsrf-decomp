/* cflags: /Oy- */
// An item of a group: 0x14 bytes.
struct Item_00047160 {
    char unknown_00[0x14];
};

// A group of items: 0x80 bytes.
struct Group_00047160 {
    int unknown_00;
    Item_00047160 *items;
    char unknown_08[0x64];
    unsigned int count;
    int unknown_70;
    int single;
    char unknown_78[0x08];
};

// A pair in the scratch block at 0x231D40: an item and what func_0006EA90 made for it.
struct Pair_00047160 {
    Item_00047160 *item;
    int handle;
};

extern unsigned char data_00231D40[];

int __stdcall func_0006EA90(void *item);

struct Object_00047470 {
    char unknown_00[0x6c];
    int *handles;
    unsigned int handleCount;

    void func_00047160(Group_00047160 *groups, unsigned int groupCount);
};

// Makes a handle (func_0006EA90) for each distinct item of the groups (only the first item of a group whose `single`
// is clear), and keeps the handles in a new array.
void Object_00047470::func_00047160(Group_00047160 *groups, unsigned int groupCount)
{
    Pair_00047160 *pairs = (Pair_00047160 *)data_00231D40;
    unsigned int count = 0;
    for (unsigned int i = 0; i < groupCount; i++) {
        Item_00047160 *item = groups[i].items;
        unsigned int n = groups[i].count;
        if (item != 0 && groups[i].single == 0) {
            n = 1;
        }
        for (unsigned int j = 0; j < n; j++, item++) {
            for (unsigned int k = 0; k < count; k++) {
                if (item == pairs[k].item) {
                    goto next;
                }
            }
            pairs[count].item = item;
            pairs[count].handle = func_0006EA90(item);
            count++;
        next:;
        }
    }
    if (count > 0) {
        handles = (int *)operator new(count * 4);
        handleCount = count;
        for (unsigned int i = 0; i < count; i++) {
            handles[i] = pairs[i].handle;
        }
    }
}
