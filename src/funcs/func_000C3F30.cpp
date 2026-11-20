// An item of the owner's list at 0xd0 (linked at 0x74).
struct Item_000C3F30 {
    char unknown_00[0x4c];
    unsigned int flags;
    char unknown_50[0x24];
    Item_000C3F30 *next;
};

// The owner at +4.
struct Owner_000C3F30 {
    char unknown_00[0xa4];
    unsigned int flags;
    char unknown_a8[0x28];
    Item_000C3F30 *items;
};

// The state machine whose table is at 0x1CDDB8; its slot 0 (func_000C3D90) runs entry `state` of the
// member-function table at 0x216148.
struct Object_000C3D90 {
    int unknown_00;
    Owner_000C3F30 *owner;
    int state;
    int count;

    void func_000C3F30();
};

// Entry 4 of that table: for up to 600 calls, waits while any of the owner's items has bit 31 set; then state 0
// and the owner's flags 2, 8 and 4 cleared.
void Object_000C3D90::func_000C3F30()
{
    if (count++ < 600) {
        for (Item_000C3F30 *item = owner->items; item; item = item->next) {
            if (item->flags & 0x80000000) {
                return;
            }
        }
    }
    state = 0;
    owner->flags &= ~2;
    owner->flags &= ~8;
    owner->flags &= ~4;
}
