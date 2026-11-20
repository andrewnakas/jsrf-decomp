struct Motion_0005F060;

// One row of data_0020E910 (0x18 bytes): the motion, the alternative motion, and two more variants (-1 for none).
struct Row_000A0280 {
    int motion;
    int alternative;
    int first;
    int second;
    char unknown_10[8];
};

extern Row_000A0280 data_0020E910[];

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x47c];
    Motion_0005F060 *motions[0x205];

    Motion_0005F060 *func_000A01F0(int index, int variant);
};

// The motion of row `index` (at 0x47c): variant 1 or 2 (the fields at 8 and 0xc of the row) when the row has
// it, else the row's motion.
Motion_0005F060 *Object_000A1C50::func_000A01F0(int index, int variant)
{
    int slot;
    switch (variant) {
    case 1:
        slot = data_0020E910[index].first;
        if (slot >= 0) {
            return motions[slot];
        }
        break;
    case 2:
        slot = data_0020E910[index].second;
        if (slot >= 0) {
            return motions[slot];
        }
        break;
    }
    return motions[data_0020E910[index].motion];
}
