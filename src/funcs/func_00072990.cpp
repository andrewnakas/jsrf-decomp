struct Entry_00251DE8 {
    unsigned char flags;
    char unknown_01[0x3f];
};

extern Entry_00251DE8 data_00251DE8[];

struct Object_00072990 {
    char unknown_00[0xa0];
    int index;

    int func_00072990();
};

// Says whether flag 4 is set in the 64-byte entry at 0x251DE8 the index at +0xa0 picks.
int Object_00072990::func_00072990()
{
    int result = 0;
    if (data_00251DE8[index].flags & 4) {
        result = 1;
    }
    return result;
}
