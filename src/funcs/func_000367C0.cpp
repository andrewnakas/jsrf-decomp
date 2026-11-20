// One of the 25 entries at 0x230DD0 (func_00036820 reads `busy`).
struct Entry_00230DD0 {
    int unknown_00;
    int unknown_04;
    int unknown_08;
    int busy;
};

extern Entry_00230DD0 data_00230DD0[];
extern int data_00230DC8;

struct Object_000265A0 {
    char unknown_0000[0x16b0];
    int unknown_16b0;
    char unknown_16b4[4];
    int unknown_16b8;
    int unknown_16bc;
    int flags[25];

    int func_000367C0(int index);
};

// Handler 14 of the table at 0x1EC068: keeps `index` at +0x16b8; while its 0x230DD0 entry is busy, 0xe into +0x16b0;
// otherwise marks it at +0x16c0, clears +0x16bc and +0x16b0 and stores 7 at 0x230DC8. Returns 1.
int Object_000265A0::func_000367C0(int index)
{
    unknown_16b8 = index;
    if (data_00230DD0[index].busy) {
        unknown_16b0 = 0xe;
        return 1;
    }
    flags[index] = 1;
    unknown_16bc = 0;
    unknown_16b0 = 0;
    data_00230DC8 = 7;
    return 1;
}
