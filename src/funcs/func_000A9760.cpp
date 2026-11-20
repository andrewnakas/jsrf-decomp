// One entry of the array at 0x44 (0x1cc bytes).
struct Entry_000A9760 {
    unsigned int flags;
    char unknown_04[0x60];
    unsigned int flags_64;
    char unknown_68[0x164];
};

struct Object_000A9760 {
    char unknown_00[0x44];
    Entry_000A9760 *entries;

    void func_000A9760(int index, int which, unsigned int mask, int set);
};

// Sets (or, with set 0, clears) the mask in the entry's flags at 0 (which 1) or at 0x64 (any other which).
void Object_000A9760::func_000A9760(int index, int which, unsigned int mask, int set)
{
    if (set) {
        switch (which) {
        case 1:
            entries[index].flags |= mask;
            break;
        default:
            entries[index].flags_64 |= mask;
            break;
        }
    } else {
        switch (which) {
        case 1:
            entries[index].flags &= ~mask;
            break;
        default:
            entries[index].flags_64 &= ~mask;
            break;
        }
    }
}
