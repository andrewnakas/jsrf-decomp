// A slot of the table at +0xe8 (0x28 bytes).
struct Slot_00071680 {
    int first;
    int second;
    int unknown_08;
    int owner;
    char unknown_10[0x18];
};

struct Object_00070850 {
    char unknown_000[0xb0];
    int firsts[4];
    int seconds[4];
    char unknown_0d0[0x18];
    Slot_00071680 slots[1];

    int func_00071380(int id, int kind, unsigned int flags);
    int func_00071680(int id, int owner);
};

// Finds a slot for `id` (func_00071380) of the first of seven kinds that has one, gives it to `owner` and notes its
// two words for the owner; returns the slot, or -1.
int Object_00070850::func_00071680(int id, int owner)
{
    for (unsigned int i = 0; i < 7; i++) {
        int kind;
        switch (i) {
        case 0:
            kind = 0;
            break;
        case 1:
            kind = 3;
            break;
        case 2:
            kind = 8;
            break;
        case 3:
            kind = 0xe;
            break;
        case 4:
            kind = 0x13;
            break;
        case 5:
            kind = 0x16;
            break;
        case 6:
            kind = 0x17;
            break;
        default:
            kind = -1;
            break;
        }
        int slot = func_00071380(id, kind, 0xc0000000);
        if (slot >= 0) {
            slots[slot].owner = owner;
            firsts[owner] = slots[slot].first;
            seconds[owner] = slots[slot].second;
            return slot;
        }
    }
    return -1;
}
