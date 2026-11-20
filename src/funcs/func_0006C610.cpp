struct Entry_0006C610 {
    char unknown_000[0x178];
    int key;
    int unknown_17c;
    unsigned int count;
    char unknown_184[8];
    Entry_0006C610 *next;
};

struct Item_0006C640 {
    char unknown_00[0x10];
    int unknown_10;
    int unknown_14;
    int unknown_18;
    int unknown_1c;
    int unknown_20;
    int unknown_24;
    int unknown_28;
    int unknown_2c;
    int unknown_30;
    Item_0006C640 *next;
};

struct Object_000149B0 {
    int unknown_00;
    Entry_0006C610 *entries;
    char unknown_08[8];
    Item_0006C640 **tail;

    Entry_0006C610 *func_0006C610(int key);
    void func_0006C640(Item_0006C640 *item, int first, int second, int third, int fourth);
    int func_0006C680(int count, int value);
};

// The entry of the list at +0x4 (linked at +0x18c) whose key (+0x178) matches, or 0.
Entry_0006C610 *Object_000149B0::func_0006C610(int key)
{
    for (Entry_0006C610 *entry = entries; entry; entry = entry->next) {
        if (entry->key == key) {
            return entry;
        }
    }
    return 0;
}
