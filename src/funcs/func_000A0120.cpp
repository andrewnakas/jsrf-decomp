struct Entry_002104A0 {
    char unknown_00[0x30];
};

struct Pair_002104A0 {
    Entry_002104A0 first;
    Entry_002104A0 second;
};

extern Pair_002104A0 data_002104A0[];

struct Object_000A1C50 {
    char unknown_000[0xe70];
    int alternate;

    Entry_002104A0 *func_000A0120(int index);
};

// The entry for the index in the table of pairs data_002104A0: the second of the pair when the field at
// 0xe70 is set, the first otherwise.
Entry_002104A0 *Object_000A1C50::func_000A0120(int index)
{
    if (alternate) {
        return &data_002104A0[index].second;
    }
    return &data_002104A0[index].first;
}
