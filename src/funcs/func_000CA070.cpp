struct Item_000CA070 {
    int value;
    char unknown_04[0x34];
    Item_000CA070 *next;
};

struct Object_000CA070 {
    char unknown_000[0x90];
    unsigned int flags;
    char unknown_094[0x308];
    Item_000CA070 *items;

    void func_000CA070();
};

// Unless flag 4 at 0x90 is already set: sets it when an item of the list at 0x39c (linked at 0x38) has a
// first field of 0.
void Object_000CA070::func_000CA070()
{
    if (!(flags & 4)) {
        for (Item_000CA070 *item = items; item; item = item->next) {
            if (!item->value) {
                flags |= 4;
                return;
            }
        }
    }
}
