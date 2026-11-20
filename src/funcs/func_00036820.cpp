struct Entry_00230DD0 {
    int unknown_00;
    int unknown_04;
    int unknown_08;
    int busy;
};

extern Entry_00230DD0 data_00230DD0[];

struct Object_000265A0 {
    int func_00036820(int index);
};

// Handler in the table at 0x1EC178 (slot 14, called with one argument at 0x256e5): the last word of an entry of
// the 25-entry table at 0x230DD0 (func_00036760 clears it, func_000367C0 tests the same word).
int Object_000265A0::func_00036820(int index)
{
    return data_00230DD0[index].busy;
}
