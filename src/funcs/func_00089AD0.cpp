// An entry of the player's list at +0x258: its kind, a byte at +5, a byte at +0x18 and the next entry (+0x38).
struct Target_0008E380 {
    int kind;
    char unknown_04;
    char unknown_05;
    char unknown_06[0x12];
    unsigned char unknown_18;
    char unknown_19[0x1f];
    Target_0008E380 *next;
};

// The player.
struct Object_000A1C50 {
    char unknown_000[0x258];
    Target_0008E380 *targets;

    int func_00089AD0();
};

// Takes 1 << the byte at +0x18 of the last entry of kind 1 or 10 whose byte at +5 is not 2, and maps it:
// 8 -> 4, 0x10 -> 5, 0xa -> 2, 0x12 -> 3, 0xc -> 6, 0x14 -> 7, none -> 0, any other -> 1.
int Object_000A1C50::func_00089AD0()
{
    int mask = 0;
    for (Target_0008E380 *target = targets; target; target = target->next) {
        if ((target->kind == 1 || target->kind == 10) && target->unknown_05 != 2)
            mask = 1 << target->unknown_18;
    }
    if (mask) {
        if (mask == 8)
            return 4;
        if (mask == 0x10)
            return 5;
        if (mask == 0xa)
            return 2;
        if (mask == 0x12)
            return 3;
        if (mask == 0xc)
            return 6;
        if (mask == 0x14)
            return 7;
        return 1;
    }
    return 0;
}
