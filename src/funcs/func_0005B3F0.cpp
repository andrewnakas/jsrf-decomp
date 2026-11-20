struct Object_00039BE0 {
    int func_00039D40(int *values, unsigned int count);
};

extern Object_00039BE0 data_001EFFB0;

struct Setup_0004CA20;

// One of the 0x54-byte entries of the list at +0x174 of the block at +0x1040: the condition values it waits for
// (+0, +4), its kind (+0x10) and, for kind 0xef, whether the set-up took (+0x30).
struct Entry_0005BA00 {
    int *values;
    unsigned int count;
    char unknown_08[8];
    int kind;
    char unknown_14[0x1c];
    int ready;
    char unknown_34[0x20];
};

struct Block_0005BA00 {
    char unknown_000[0x174];
    Entry_0005BA00 *entries;
    unsigned int count;
};

struct Object_0004ABA0 {
    char unknown_0000[0x2b0];
    unsigned int unknown_2b0;
    char unknown_2b4[0xd04];
    Entry_0005BA00 *current;
    char unknown_0fbc[0x84];
    Block_0005BA00 *block;

    void func_0004CA20(Setup_0004CA20 *setup);
    void func_000585E0(Entry_0005BA00 *entries, unsigned int index);
    int func_0005B3F0();
};

// Walks the block's entries from +0x2b0 on, skipping those whose condition values data_001EFFB0 does not accept
// (func_00039D40): kinds 0x7e, 0x7f, 0xe2, 0xe3, 0xe8 - 0xea and 0xed stop the walk, and kind 0xef stops it when its
// set-up (func_0004CA20) took; every other kind runs func_000585E0. A stop keeps the entry at +0xfb8, steps past it
// and returns its kind; the end of the list returns -1.
int Object_0004ABA0::func_0005B3F0()
{
    Entry_0005BA00 *entries = block->entries;
    for (; unknown_2b0 < block->count; unknown_2b0++) {
        if (!data_001EFFB0.func_00039D40(entries[unknown_2b0].values, entries[unknown_2b0].count)) {
            continue;
        }
        int kind = entries[unknown_2b0].kind;
        switch (kind) {
        case 0x7e:
        case 0x7f:
        case 0xe2:
        case 0xe3:
        case 0xe8:
        case 0xe9:
        case 0xea:
        case 0xed:
            current = &entries[unknown_2b0];
            unknown_2b0++;
            return kind;
        case 0xef:
            func_0004CA20((Setup_0004CA20 *)&entries[unknown_2b0]);
            if (entries[unknown_2b0].ready) {
                current = &entries[unknown_2b0];
                unknown_2b0++;
                return kind;
            }
            break;
        default:
            func_000585E0(entries, unknown_2b0);
            break;
        }
    }
    return -1;
}
