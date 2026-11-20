// One entry of the array at 0x44 (0x1d0 bytes): flags at 0x0 and at 0x5c.
struct Entry_000ACD40 {
    unsigned int flags;
    char unknown_04[0x58];
    unsigned int flags_5c;
    char unknown_60[0x170];
};

struct Object_000ACD40 {
    char unknown_00[0x44];
    Entry_000ACD40 *entries;

    void func_000ACCE0(int index, int which, unsigned int mask, int set);
};

// Sets (or clears) the mask in the flags of entry `index`: those at 0x0 for `which` 1, else those at 0x5c.
void Object_000ACD40::func_000ACCE0(int index, int which, unsigned int mask, int set)
{
    if (set) {
        switch (which) {
        case 1:
            entries[index].flags |= mask;
            break;
        default:
            entries[index].flags_5c |= mask;
            break;
        }
    } else {
        switch (which) {
        case 1:
            entries[index].flags &= ~mask;
            break;
        default:
            entries[index].flags_5c &= ~mask;
            break;
        }
    }
}
