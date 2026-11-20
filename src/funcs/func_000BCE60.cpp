// One entry of the array at 0x44 (0x1d0 bytes).
struct Entry_000BCED0 {
    char unknown_00[0x48];
    unsigned int flags;
    char unknown_4c[0x48];
    unsigned int secondFlags;
    char unknown_98[0x138];
};

struct Object_000BCED0 {
    char unknown_00[0x44];
    Entry_000BCED0 *entries;

    void func_000BCE60(int index, int which, unsigned int bits, int set);
};

void Object_000BCED0::func_000BCE60(int index, int which, unsigned int bits, int set)
{
    if (set) {
        switch (which) {
        case 1:
            entries[index].secondFlags |= bits;
            break;
        default:
            entries[index].flags |= bits;
            break;
        }
    } else {
        switch (which) {
        case 1:
            entries[index].secondFlags &= ~bits;
            break;
        default:
            entries[index].flags &= ~bits;
            break;
        }
    }
}
