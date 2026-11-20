struct Item_00047E10 {
    char unknown_00[8];
    unsigned int flags;
};

// A 0x80-byte record whose first word points to an item.
struct Slot_00047E10 {
    Item_00047E10 *item;
    char unknown_04[0x7c];
};

struct Object_00047470 {
    virtual ~Object_00047470();

    char unknown_04[0x10];
    int unknown_14;
    char unknown_18[0xc];
    unsigned int flags;

    void func_00047E10(Slot_00047E10 *slots, int number);
};

// From the item of record `number` (counted from 1), if any: +0x14 = 1 or 2 by its flag 8 when it has flag 0x1000,
// otherwise 3 for flags 0x12 and 0; without its flag 0x10, clears flag 1 at +0x24.
void Object_00047470::func_00047E10(Slot_00047E10 *slots, int number)
{
    Item_00047E10 *item = slots[number - 1].item;
    if (item) {
        if (item->flags & 0x1000)
            unknown_14 = (item->flags & 8) ? 1 : 2;
        else
            unknown_14 = (item->flags == 0x12) ? 3 : 0;
        if (!(item->flags & 0x10))
            flags &= ~1;
    }
}
