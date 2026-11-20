// A slot of the table at +0xe8 (0x28 bytes): four linked slots from +0x10.
struct Slot_00071680 {
    int first;
    int second;
    int unknown_08;
    int owner;
    int links[4];
    char unknown_20[0x8];
};

struct Object_00070850 {
    char unknown_000[0xb0];
    int firsts[4];
    int seconds[4];
    char unknown_0d0[0x18];
    Slot_00071680 slots[1];

    int func_00070570(int owner, int slot, unsigned int flags);
};

// Entry 4 of the table at 0x20CC6C: unless the slot's first linked slot (+0x10) is already the owner's or
// bit 30 of the flags is set, frees the slot, gives the linked one to the owner and notes its two words for the owner.
// Returns the linked slot.
int Object_00070850::func_00070570(int owner, int slot, unsigned int flags)
{
    int link = slots[slot].links[0];
    if (slots[link].owner != owner && !(flags & 0x40000000)) {
        slots[slot].owner = -1;
        slots[link].owner = owner;
        firsts[owner] = slots[link].first;
        seconds[owner] = slots[link].second;
    }
    return link;
}
